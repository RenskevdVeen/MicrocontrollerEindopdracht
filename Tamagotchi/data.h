#ifndef _ledmatrix_H
#define _ledmatrix_H

/*
 * data.h
 *
 * Created: 20-3-2019 12:12:01
 *  Author: Renske
 */ 


#include <avr/io.h>

 void twi_start(void);
 void twi_stop(void);
 void twi_tx(unsigned char data);
 void twi_init(void);
 void write_data(unsigned char,unsigned char);
 
  #endif
  