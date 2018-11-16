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

void Init_AD(void)
{
		ADC_CSR=0x08;      //选择通道AIN8
		ADC_CR2|=0x08;     //	数据排列,右对齐
		//ADC_TDRL=0x20;
}

void main(void)
{
		u8 i;
		PB_DDR = 0xff;     
		PB_CR1 = 0xff;
		
		PD_DDR = 0xff;
		PD_CR1 = 0xff;
		
		Init_AD();
		while (1)
		{
				ADC_CR1|=0x01;         //将CR1寄存器的最低位置1,开启AD转换
				for(i=0;i<100;i++);    //延时一段时间，至少7uS，保证ADC模块的上电完成
				ADC_CR1|=0x01;         //再次将CR1寄存器的最低位置1,开启AD转换

				while((ADC_CSR & 0x80)!=0x80);  // 等待转换结束
				PB_ODR=ADC_DRH;        //把高位用PB显示出来
				PD_ODR=ADC_DRL;        //把低位用PD显示出来
				ADC_CSR&=(~0x80);      //软件清零 转换结束 标志位
		}
}