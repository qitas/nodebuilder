/********************************************************************************************************
*
* File                : TIM2.c
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

u8 i;

void Init_Tim2(void)
{
	TIM2_IER=0x01;    //开启中断
	TIM2_EGR=0x01;    //产生新事件
	
	TIM2_CNTRH=0x13;  //设置计数器寄存器(十进制为5000)
	TIM2_CNTRL=0x88;
	
	TIM2_ARRH=0x13;   //设置自动装载寄存器
	TIM2_ARRL=0x88;
	
	TIM2_PSCR=0x02;   //设置预分频为2M的输入晶振分频成500K
	
	TIM2_CR1=0x01;    //开启定时器2
}

void Init_GPIO(void)
{
	PD_DDR=0xff;
	PD_CR1=0xff;
}
/********************************************************
用TIM2产生0.01S的时钟~然后循环100次产生1S的延迟~用PD显示
********************************************************/
void main(void)
{
	Init_GPIO();
	Init_Tim2();
	_asm("rim");      //开启全局中断
	while (1);
}

//中断程序格式
@far @interrupt void TIM2_UPD_OVF_IRQHandler (void)
{
	TIM2_SR1=0x00;
	i++;
	if(i==100)
	{
		PD_ODR=PD_ODR^0xff;
		i=0;
	}
	return;
}