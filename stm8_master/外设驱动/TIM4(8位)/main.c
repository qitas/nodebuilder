/********************************************************************************************************
*
* File                : TIM4.c
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

u8 i=0;
void Init_Tim4(void)
{
	TIM4_IER=0x01;    //使能中断
	TIM4_EGR=0x01;    //使能自动更新
	TIM4_CNTR=255;    //填写计数器
	TIM4_ARR=255;     //自动重新装载
	TIM4_PSCR=0x07;   //分频
	TIM4_CR1=0x01;    //使能计数器
}

void Init_GPIO(void)
{
	PD_DDR=0xff;
	PD_CR1=0xff;
}

void main(void)
{
	Init_GPIO();
	Init_Tim4();
	_asm("rim");
	while (1);
}

@far @interrupt void TIM4_UPD_OVF_IRQHandler (void)
{
	TIM4_SR=0x00;
	i++;
	if(i==61)
	{
		PD_ODR=PD_ODR^0xff;
		i=0;
	}
	return;
}