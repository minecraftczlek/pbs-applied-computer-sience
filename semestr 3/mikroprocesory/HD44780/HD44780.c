/*
 * HD44780.c
 *
 *  Created on: Dec 18, 2022
 *      Author: maciej
 */

#include "HD44780.h"

void lcd_datapins_out(void){ //ustawieanie pinów jako wyjśćie
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;

	GPIO_InitStructure.Pin = LCD_D4_Pin;
	HAL_GPIO_Init(LCD_D4_GPIO_Port, &GPIO_InitStructure);
	GPIO_InitStructure.Pin = LCD_D5_Pin;
	HAL_GPIO_Init(LCD_D5_GPIO_Port, &GPIO_InitStructure);
	GPIO_InitStructure.Pin = LCD_D6_Pin;
	HAL_GPIO_Init(LCD_D6_GPIO_Port, &GPIO_InitStructure);
	GPIO_InitStructure.Pin = LCD_D7_Pin;
	HAL_GPIO_Init(LCD_D7_GPIO_Port, &GPIO_InitStructure);
}

void lcd_datapins_in(void){ //ustawieanie pinów jako wejście
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;

	GPIO_InitStructure.Pin = LCD_D4_Pin;
	HAL_GPIO_Init(LCD_D4_GPIO_Port, &GPIO_InitStructure);
	GPIO_InitStructure.Pin = LCD_D5_Pin;
	HAL_GPIO_Init(LCD_D5_GPIO_Port, &GPIO_InitStructure);
	GPIO_InitStructure.Pin = LCD_D6_Pin;
	HAL_GPIO_Init(LCD_D6_GPIO_Port, &GPIO_InitStructure);
	GPIO_InitStructure.Pin = LCD_D7_Pin;
	HAL_GPIO_Init(LCD_D7_GPIO_Port, &GPIO_InitStructure);
}

uint8_t lcd_readHalf(void){ //odczyt połowy bajta
	  uint8_t tmp = 0;

	  HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	  tmp |= (HAL_GPIO_ReadPin(LCD_D4_GPIO_Port, LCD_D4_Pin) << 0);
	  tmp |= (HAL_GPIO_ReadPin(LCD_D5_GPIO_Port, LCD_D5_Pin) << 1);
	  tmp |= (HAL_GPIO_ReadPin(LCD_D6_GPIO_Port, LCD_D6_Pin) << 2);
	  tmp |= (HAL_GPIO_ReadPin(LCD_D7_GPIO_Port, LCD_D7_Pin) << 3);
	  HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);

	  return tmp;
}

uint8_t lcd_read_byte(void){ //odczyt całego bajta
	uint8_t result=0;

	lcd_datapins_in();
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_SET);

	result = (lcd_readHalf() << 4);
	result |= lcd_readHalf();

	return result;
}

uint8_t lcd_readFlag(void){
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
	return lcd_read_byte();
}

void lcd_sendHalf(uint8_t data){ //wysyłąnie połowy bajta
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (data & 0x01));
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (data & 0x02));
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (data & 0x04));
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (data & 0x08));
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
}

void lcd_write_byte(uint8_t data){ //wysyłąnie całego bajta
	lcd_datapins_out();
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);

	lcd_sendHalf(data >> 4);
	lcd_sendHalf(data);

	while(lcd_readFlag() & 0x80 );
}

void lcd_write_cmd(uint8_t cmd){ //wysyłanie komendy
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
	lcd_write_byte(cmd);
}

void lcd_write_char(char data){ //wysyłąnie znaku
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET);
	lcd_write_byte(data);
}

void lcd_init(){ //inicjalizacja wyświetlacza
	HAL_Delay(100);

	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);

	lcd_sendHalf(0x03);
	HAL_Delay(5);
	lcd_sendHalf(0x03);
	HAL_Delay(1);
	lcd_sendHalf(0x03);
	HAL_Delay(1);
	lcd_sendHalf(0x02);
	HAL_Delay(1);

	lcd_write_cmd( LCD_FUNC | LCD_4_BIT | LCDC_TWO_LINE | LCDC_FONT_5x7);
	lcd_write_cmd( LCD_ONOFF | LCD_DISP_ON );
	lcd_write_cmd( LCD_CLEAR );
	HAL_Delay(5);
	lcd_write_cmd( LCDC_ENTRY_MODE | LCD_EM_SHIFT_CURSOR | LCD_EM_RIGHT );
}

void lcd_str(char *text){ //wypisywanie słowa
	while(*text)lcd_write_char(*text++);
}

void lcd_locate(uint8_t x, uint8_t y){ //ustawienie kursora
	switch(y){
		case 0:
			lcd_write_cmd( LCDC_SET_DDRAM | (LCD_LINE1 + x) );
		break;
		case 1:
			lcd_write_cmd( LCDC_SET_DDRAM | (LCD_LINE2 + x) );
		break;
	}
}
