/*
 * lcd.h
 *
 * Created: 20-3-2019 14:17:17
 *  Author: Renske
 */ 
void lcd_strobe_lcd_e(void);
void init_4bits_mode(void);
void lcd_write_string(char *str);
void lcd_write_data(unsigned char byte);
void lcd_write_cmd(unsigned char byte);
void set_cursor(void);
void clear_lcd_screen(void);