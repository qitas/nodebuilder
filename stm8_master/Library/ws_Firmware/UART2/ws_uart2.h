/********************************************************************************************************
*
* File                : ws_UAER2.h
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

#ifndef _WS_UART2_H
#define _WS_UART2_H

#include <ws_lcd_st7920.h>

void Init_UART2(void)
{
		UART2_CR1=0x00;
		UART2_CR2=0x00;
		UART2_CR3=0x00;
		
		// 设置波特率，必须注意以下几点：
		//    (1) 必须先写BRR2
		//    (2) BRR1存放的是分频系数的第11位到第4位，
		//    (3) BRR2存放的是分频系数的第15位到第12位，和第3位
		//        到第0位
		// 例如对于波特率位9600时，分频系数=2000000/9600=208
		// 对应的十六进制数为00D0，BBR1=0D,BBR2=00


		UART2_BRR2=0x00;
		UART2_BRR1=0x0d;
		
		UART2_CR2=0x2c;//允许接收，发送，开接收中断
		
}

void UART2_sendchar(u8 data)
{
		while((UART2_SR & 0x80)==0x00);
		UART2_DR=data;
}

@far @interrupt void UART2_Recv_IRQHandler (void)
{
	u8 data;
	data=UART2_DR;
	showLine(6,2,lcd_buffer,"0x%x2",(u16)data);
	return;
}

#endif /*_WS_UART3_H*/