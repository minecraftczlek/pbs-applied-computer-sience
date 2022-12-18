/*
 * HD44780.c
 *
 *  Created on: 15 gru 2022
 *      Author: maciej Niedźwiecki
 */
#include "main.h"

#define LCD_CLEAR					0x01
#define LCD_HOME					0x02
#define LCDC_ENTRY_MODE				0x04
	#define LCD_EM_SHIFT_CURSOR		    0x00
	#define LCD_EM_SHIFT_DISPLAY	 	0x01
	#define LCD_EM_LEFT		   			0x00
	#define LCD_EM_RIGHT				0x02
#define LCD_ONOFF					0x08
	#define LCD_DISP_ON				    0x04
	#define LCD_CURSOR_ON				0x02
	#define LCDC_CURSOR_OFF				0x00
	#define LCDC_BLINK_ON				0x01
	#define LCDC_BLINK_OFF				0x00
#define LCD_SHIFT					0x10
	#define LCDC_SHIFT_DISP				0x08
	#define LCDC_SHIFT_CURSOR			0x00
	#define LCDC_SHIFT_RIGHT			0x04
	#define LCDC_SHIFT_LEFT				0x00
#define LCD_FUNC					0x20
	#define LCD_8_BIT					0x10
	#define LCD_4_BIT					0x00
	#define LCDC_TWO_LINE				0x08
	#define LCDC_FONT_5x10				0x04
	#define LCDC_FONT_5x7				0x00
#define LCDC_SET_CGRAM				0x40
#define LCDC_SET_DDRAM				0x80
#define LCD_LINE1 		0x00
#define LCD_LINE2 		0x40

void lcd_datapins_out(void); //ustawieanie pinów jako wyjśćie

void lcd_datapins_in(void); //ustawieanie pinów jako wejście

uint8_t lcd_readHalf(void); //odczyt połowy bajta

uint8_t lcd_read_byte(void); //odczyt całego bajta

uint8_t lcd_readFlag(void);

void lcd_sendHalf(uint8_t data); //wysyłąnie połowy bajta

void lcd_write_byte(uint8_t data); //wysyłąnie całego bajta

void lcd_write_cmd(uint8_t cmd); //wysyłanie komendy

void lcd_write_char(char data); //wysyłąnie znaku

void lcd_init(); //inicjalizacja wyświetlacza

void lcd_str(char *text); //wypisywanie słowa

void lcd_locate(uint8_t x, uint8_t y); //ustawienie kursora
