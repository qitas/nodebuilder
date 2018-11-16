/********************************************************************************************************
*
* File                : ws_i2c_src.h
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

#ifndef _WS_I2C_SRC_H
#define _WS_I2C_SRC_H

void I2C_Init(void)
{
		I2C_FREQR=0x0f;    //设置频率寄存器
		I2C_CCRH=0x00;     //设置始终寄存器高位
		I2C_CCRL=0x50;     //设置始终寄存器低位
		I2C_TRISER=0x11;   //设置最大SCL上升时间
		I2C_CR1|=0x01;     //使能I2C模块
		I2C_Ack();         //设置匹配应答
		I2C_CR2|=0x08;     //设置接收应答
}


void I2C_Start(void)
{
	I2C_busy();
	I2C_start();
	while(I2C_SBask==0);
}
/*-------------传送地址---------------*/
void I2C_SendDAdr(u8 Add)
{
	I2C_writebyte(Add);	
	while(I2C_addrask==0);
	I2C_busy();
}

/*----------------发送数据&接收数据------------------*/
void I2C_SendDat(u8 data)
{
	I2C_writebyte(data);
	I2C_busy();
	while(I2C_TxEask==0);
}

u8 I2C_RcvDat(void)
{
	u8 i;
	while(I2C_RxNeask==0);
	abc:
	if(I2C_BTF==0x04)
	{i=I2C_DR;}
	else goto abc;
	if(I2C_BTF==0){}
	else goto abc;
	return i;
}
/*
u8 I2C_ReadAbit(u8 addr)
{
	u8 i;
	I2C_Start();
	I2C_SendDAdr(0x41);
	i=I2C_RcvDat();
	I2C_stop();
	return i;
}

void I2C_WriteAbit(u8 addr,u8 data)
{
	I2C_Start();
	I2C_SendDAdr(addr);
	I2C_SendDat(data);
	I2C_stop();
}*/

#endif /*_WS_I2C_SRC_H*/
