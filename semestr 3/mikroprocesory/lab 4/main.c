/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "morsea.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
#define USART_TXBUF_LEN 1512 // dlugosc bufora Tx (transmisja danych)
#define USART_RXBUF_LEN 1024 // dlugosc bufora Rx (odbiór danych)
uint8_t USART_TxBuf[USART_TXBUF_LEN], // deklaracja bufora Tx o długości USART_TXBUF_LEN
		USART_RxBuf[USART_RXBUF_LEN]; // deklaracja bufora Rx o długości USART_TXBUF_LEN

__IO int USART_TX_Empty = 0, // pierwsze wolne miejsce w buforze Tx
		 USART_TX_Busy = 0, // pierwsze zajęte miejsce w buforze Tx
		 USART_RX_Empty = 0, // pierwsze wolne miejsce w buforze Rx
		 USART_RX_Busy = 0; // pierwsze zajęte miejsce w buforze Rx
uint8_t mode = 0;
//	0 - brak trybu
//	1 - tryb mrugania
// 	2 - tryb morsea
uint8_t delay = 0;
uint8_t morsea_bufor[1024];
uint8_t morsea_index;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int8_t USART_getchar() { // odczyt znaku z bufora Rx
	int8_t tmp;
	if(USART_RX_Empty != USART_RX_Busy) { // jeśli w buforze Rx są dane
		tmp = USART_RxBuf[USART_RX_Busy]; // odczyt znaku z bufora
		__disable_irq(); // wyłączenie przerwań
		USART_RX_Busy++; // zwiększenie wskaźnika zajętych miejsc w buforze Rx
		if(USART_RX_Busy >= USART_RXBUF_LEN) USART_RX_Busy = 0; // jeśli przekroczono długość bufora, to wróć na początek
		__enable_irq(); // włączenie przerwań
		return tmp;
	}else return 0; // jeśli w buforze Rx nie ma danych, to zwróć 0
}

//pobieranie komendy
void USART_getCommand(uint8_t command[255]){
	uint8_t tmp = 0, i = 0;
	while(tmp != ';'){
		tmp = USART_getchar();
		if(tmp){
			command[i] = tmp;
			i++;
		}

	}
}

void USART_fsend(char* format, ...) { // funkcja dodająca dane do bufora Tx
	char tmp_rs[128]; // bufor tymczasowy
	int i; // zmienna do iteracji w pętli for
	__IO int idx;
	va_list arglist; // deklaracja listy argumentów
	va_start(arglist, format); // inicjalizacja listy argumentów
	vsprintf(tmp_rs, format, arglist); // przekazanie do bufora tymczasowego danych z listy argumentów
	va_end(arglist); // zakończenie listy argumentów
	idx = USART_TX_Empty; // idx przyjmuje wartość wskaźnika na pierwsze wolne miejsce w buforze Tx
	for(i = 0; i < strlen(tmp_rs); i++) { // pętla idąca po długości bufora tymczasowego
		USART_TxBuf[idx] = tmp_rs[i]; // przekazanie danych z bufora tymczasowego do bufora Tx
		idx++; // zwiększenie wskaźnika idx o 1
		if(idx == USART_TXBUF_LEN) idx = 0; // jeżeli idx przekroczy długośc bufora to ustaw idx na początek bufora = 0
	}
	__disable_irq(); // wyłączenie przerwań
	if(USART_TX_Empty == USART_TX_Busy && __HAL_UART_GET_FLAG(&huart2, UART_FLAG_TXE == SET)) { // jeżeli bufor Tx jest pusty i flaga TXE jest ustawiona
		USART_TX_Empty = idx; // ustaw idx jako pierwsze wolne miejsce w buforze Tx
		uint8_t tmp = USART_TxBuf[USART_TX_Busy]; // zmienna tymczasowa przyjmuje wartość pierwszego znaku w buforze Tx
		USART_TX_Busy++; // zwiększenie wskaźnika zajętych miejsc w buforze Tx
		if(USART_TX_Busy >= USART_TXBUF_LEN) USART_TX_Busy = 0; // jeśli przekroczono długość bufora, to wróć na początek
		HAL_UART_Transmit_IT(&huart2, &tmp, 1); // uruchomienie przerwania transmitującego (wysłanie znaku)
	}
	else USART_TX_Empty = idx; // jeżeli bufor Tx nie jest pusty to ustaw idx jako pierwsze wolne miejsce w buforze Tx
	__enable_irq();
}

// przerwanie transmitujące UART
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if (huart == &huart2 && USART_TX_Empty != USART_TX_Busy){
		uint8_t tmp = USART_TxBuf[USART_TX_Busy];
		if(++USART_TX_Busy >= USART_TXBUF_LEN) USART_TX_Busy = 0; // zwiększenie wskaźnika busy w buforze Tx
		HAL_UART_Transmit_IT(&huart2, &tmp, 1); // wysłanie znaku
	}
}

// przerwanie odbierające UART
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (huart == &huart2) {
		if(++USART_RX_Empty >= USART_RXBUF_LEN) USART_RX_Empty = 0; //zwiększenie wskaźnika epty w buforze Rx
		HAL_UART_Receive_IT(&huart2, &USART_RxBuf[USART_RX_Empty], 1); // zapis do buforu;
	}
}

void addMorseChar(uint8_t c[10]){
	uint8_t i = 0;
	while(c[i]){
		morsea_bufor[morsea_index++] = c[i++];
		morsea_bufor[morsea_index++] = ',';
	}
	morsea_bufor[morsea_index++] = '|'; //koniec litery
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	static tmp=0;
	if (htim == &htim3){
		if(mode == 1)HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);//mruganie
		if(mode == 2){
			if(tmp)tmp=0;
			else if(morsea_bufor[morsea_index]=='.'){
				morsea_index++;
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
				htim3.Init.Period = 10 * 100;
				if (HAL_TIM_Base_Init(&htim3) != HAL_OK){
					Error_Handler();
				}tmp=1;
			}else if(morsea_bufor[morsea_index]=='-'){
				morsea_index++;
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
				htim3.Init.Period = 10 * 200;
				if (HAL_TIM_Base_Init(&htim3) != HAL_OK){
					Error_Handler();
				}tmp=1;
			}else if(morsea_bufor[morsea_index]==','){
				morsea_index++;
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
				htim3.Init.Period = 10 * 100;
				if (HAL_TIM_Base_Init(&htim3) != HAL_OK){
					Error_Handler();
				}tmp=1;
			}else if(morsea_bufor[morsea_index]=='|'){
				morsea_index++;
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
				htim3.Init.Period = 10 * 200;
				if (HAL_TIM_Base_Init(&htim3) != HAL_OK){
					Error_Handler();
				}tmp=1;
			}else if(morsea_bufor[morsea_index]==' '){
				morsea_index++;
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
				htim3.Init.Period = 10 * 300;
				if (HAL_TIM_Base_Init(&htim3) != HAL_OK){
					Error_Handler();
				}tmp=1;
			}else if(!morsea_bufor[morsea_index]){
				mode = 0;
				HAL_TIM_Base_Stop_IT(&htim3);
				USART_fsend("MORSE STOP\r\n");
			}
		}
	}
	else if(htim == &htim2){
		if(delay==1)delay=2;
		else if(delay==2){
			delay = 0;
			HAL_TIM_Base_Stop_IT(&htim2);
		}
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
//  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Base_Start_IT(&htim3);
  USART_fsend("Witaj, jestem Nucleo STM32!!!\r\n");
  HAL_UART_Receive_IT(&huart2,&USART_RxBuf[USART_RX_Empty], 1);
  uint8_t command[255],
  strLedON[8] = "LED[ON];",
  strLedOFF[9] = "LED[OFF];",
  strLedBLINK[10] = "LED[BLINK,",
  strInsertDelay[13] = "INSERT[Delay,",
  strMorsea[6] = "MORSE[";
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(!delay && mode != 2){
		  USART_getCommand(&command[0]);
		 if(!strncmp(&command[0], &strLedON, 8)){
			 mode=0;
			 HAL_TIM_Base_Stop_IT(&htim3);
			 HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin,1);
			 USART_fsend("ZAPALONO DIODE\r\n");
		 }else if(!strncmp(&command[0], &strLedOFF, 9)){
			 mode=0;
			 HAL_TIM_Base_Stop_IT(&htim3);
			 HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin,0);
			 USART_fsend("ZGASZONO DIODE\r\n");
		 }else if (!strncmp(&command[0], &strLedBLINK, 10)){
			 int x = 0, i = 10;
			 while(command[i]>=0x30 && command[i]<=0x39){
				 x *= 10;
				 x += command[i] - 0x30;
				 i++;
			 }
			 if(x>65536)continue;
			 USART_fsend("Mruganie: %dHz\r\n", x);
			 mode=1;
			 htim3.Init.Period = 10000 / x;
			 if (HAL_TIM_Base_Init(&htim3) != HAL_OK){
				Error_Handler();
			 }
			 HAL_TIM_Base_Start_IT(&htim3);
		 }else if (!strncmp(&command[0], &strInsertDelay, 13)){
			 int time = 0, i = 13;
			 while(command[i]>=0x30 && command[i]<=0x39){
				 time *= 10;
				 time += command[i] - 0x30;
				 i++;
			 }
			 USART_fsend("Delay: %dms\r\n", time);
			 int test = 10 * time;
			 htim2.Init.Period = test;
			 if (HAL_TIM_Base_Init(&htim2) != HAL_OK){
			 	Error_Handler();
			 }
			 delay=1;
			 HAL_TIM_Base_Start_IT(&htim2);
		 }else if (!strncmp(&command[0], &strMorsea, 6)){
			 USART_fsend("MORSE START\r\n");
			 morsea_index = 0;
			 HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin,0);
			 uint8_t i = 6;
			 while(command[i] != ';'){
				if(command[i] >= 0x41 && command[i] <= 0x5A)addMorseChar(&morseaLetters[command[i] - 0x41]);
				else if(command[i] >= 0x61 && command[i] <= 0x7A)addMorseChar(&morseaLetters[command[i] - 0x61]);
				else if(command[i]==' ')morsea_bufor[morsea_index++]=' ';
				i++;
			 }
			 morsea_bufor[morsea_index]=0;
			 morsea_index = 0;
			 mode = 2;
			 HAL_TIM_Base_Start_IT(&htim3);
		 }else USART_fsend("blad: komenda nie rozpoznana\r\n");
	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 8399;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 8399;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 9999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_BUTTON_Pin */
  GPIO_InitStruct.Pin = USER_BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_BUTTON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
