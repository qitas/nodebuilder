/********************************************************************************************************
*
* File                : CLK_Modify.c
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

void Init_GPIO(void)
{
		PD_DDR = 0xff;
		PD_CR1 = 0xff;
}
/***************************************************
3次改变时钟让PD连接LED闪烁速度不同
***************************************************/
void main(void)
{
		u8 i;
		Init_GPIO();
		
		while (1)
		{
			//启用内部高速晶振且无分频16MHz
			CLK_SWR=0xe1;
			CLK_CKDIVR=0x00;
			CLK_SWCR|=0x02;      //开启切换
			while((CLK_SWCR & 0x01)==0x01);
			CLK_SWCR&=(~0x02);      //关闭切换
			for(i=0;i<10;i++)
			{
				PD_ODR=0x55;
				delay_ms(500);
				PD_ODR=(~0x55);
				delay_ms(500);
			}
			//启用内部高速晶振且8分频(内部始终分频)2MHz
			CLK_SWR=0xe1;
			CLK_CKDIVR=0x18;
			CLK_SWCR|=0x02;      //开启切换
			while((CLK_SWCR & 0x01)==0x01);
			CLK_SWCR&=(~0x02);      //关闭切换
			for(i=0;i<5;i++)
			{
				PD_ODR=0x55;
				delay_ms(500);
				PD_ODR=(~0x55);
				delay_ms(500);
			}
			//启用外部高速晶振且16分频500KHz
			CLK_SWR=0xb4;
			CLK_CKDIVR=0x00;
			CLK_SWCR|=0x02;      //开启切换
			while((CLK_SWCR & 0x01)==0x01);
			CLK_SWCR&=(~0x02);      //关闭切换
			for(i=0;i<5;i++)
			{
				PD_ODR=0x55;
				delay_ms(500);
				PD_ODR=(~0x55);
				delay_ms(500);
			}
		}
}