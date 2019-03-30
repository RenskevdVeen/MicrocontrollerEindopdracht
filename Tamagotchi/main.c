/*
* Tamagotchi.c
*
* Created: 20-3-2019 11:58:04
* Author : Renske
*/
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "board.h"
#include "data.h"
#include "lcd.h"



void wait( int ms )
/*
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:
notes:			Busy wait, not very accurate. Make sure (external)
clock value is set. This is used by _delay_ms inside
util/delay.h
Version :    	Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}
void initMatrix(void){
	twi_init();
	initBoard();
	init_4bits_mode();
	
	
	DDRA = 0b11111111;

	EICRA |= (1 << ISC00);    // set INT0 to trigger on ANY logic change
	EIMSK |= (1 << INT0);     // Turns on INT0
	//enable global interrupt system
	//sei();
}

int main(void)
{
	
	initMatrix();
	

	while(1){
		
		initHealth();
		
		DDRC &= ~(1<<PC0);
		timer++;
		
		
		if (PINC & (1<<PC0)==1){
			health = 30;
		}
	}
}




