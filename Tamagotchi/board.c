/*
* board.c
*
* Created: 20-3-2019 11:59:33
*  Author: Renske
*/

int rowsize = 8;
int health = 30;

int timer = 0;

char addressOfrow[8]= {0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E};

void initBoard()
{
	clearBoard();
}
void clearBoard()
{
	for (int i = 0; i<rowsize; i++){
		write_data(addressOfrow[i],	0 );
		
	}
}

void startTamagotchi(){
	write_data(0x0e,0x1E);
	write_data(0x02, 0x21);
	write_data(0x04, 0xCA);
	write_data(0x06, 0xD0 );
	write_data(0x08, 0xD0);
	write_data(0x0A, 0xCA);
	write_data(0x0c, 0x21);
	write_data(0x00,0x1E);
}

void sadTamagotchi(){
	write_data(0x0e,0x1E);
	write_data(0x02, 0x21);
	write_data(0x04, 0xD2);
	write_data(0x06, 0xC8 );
	write_data(0x08, 0xC8);
	write_data(0x0A, 0xD2);
	write_data(0x0c, 0x21);
	write_data(0x00,0x1E);
}

void midTamagotchi(){
	write_data(0x0e,0x1E);
	write_data(0x02, 0x21);
	write_data(0x04, 0xCA);
	write_data(0x06, 0xC8 );
	write_data(0x08, 0xC8);
	write_data(0x0A, 0xCA);
	write_data(0x0c, 0x21);
	write_data(0x00,0x1E);
}
void initHealth(){
	if (timer % 1000 == 0){
		
		if (health <= 30 && health> 0){
			health = health-5;
			}if (health <= 0){
		}
	}
	
	if (health <=30 && health> 20){
		startTamagotchi();
		clear_lcd_screen();
		lcd_write_string("Im happy!");
	}
	if (health <=  20 && health> 10){
		midTamagotchi();
		clear_lcd_screen();
		lcd_write_string("Im Upset!");
	}
	if (health < 10 && health>0){
		sadTamagotchi();
		clear_lcd_screen();
		lcd_write_string("Im sad!");
	}
}


