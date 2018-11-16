/********************************************************************************************************
*
* File                : beep.c
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

main()
{ 
	unsigned char i,k;
	PD_DDR=0xff;
	PD_CR1=0xff;
	BEEP_CSR&=(~0xe0);
	BEEP_CSR|=0x20;
	BEEP_CSR|=0x40;
	while (1)
	{ 	
		for(i=0;i<10;i++)
		{
			BEEP_CSR|=0x20;
			delay_ms(1000);
			BEEP_CSR&=(~0x20);
			delay_ms(1000);
		}
	}
}