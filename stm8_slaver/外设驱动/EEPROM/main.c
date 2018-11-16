/********************************************************************************************************
*
* File                : ADC.c
* Hardware Environment: 
* Build Environment   : ST Visual Develop 4.1.6
* Version             : V1.0
* By                  : Xiao xian hui
*
*                                  (c) Copyright 2005-2010, WaveShare
*                                       http://www.waveShare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/
#include <stm8s207rb.h>
#include <system.h>

void Init_EEPROM(void)
{
	do
	{
		FLASH_DUKR=0xae;
		FLASH_DUKR=0x56;
	}while((FLASH_IAPSR & 0x08)==0);
}

void Init_GPIO(void)
{
		PD_DDR=0xff;
		PD_CR1=0xff;
}

void main(void)
{
	u8 ch;
	u8 *p;
	Init_EEPROM();
	Init_GPIO();
		
	p=(u8 *)0x40f0;
		
	*p=0x61;
		
	while((FLASH_IAPSR & 0x04)==0);
		
	PD_ODR=*p;
	while (1);
}