/********************************************************************************************************
*
* File                : ws_i2c.h
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

#ifndef _WS_I2C_h
#define _WS_I2C_h

#define I2C_busy() while((I2C_SR3&0x02)==1);
#define I2C_start() I2C_CR2|=0x01;
#define I2C_stop() I2C_CR2|=0x02;

#define I2C_Ack() I2C_CR2|=0x04;
#define I2C_NAck() I2C_CR2&=(~0x04);

#define I2C_addrask (I2C_SR1&0x02)
#define I2C_SBask (I2C_SR1&0x01)
#define I2C_TxEask (I2C_SR1&0x80)
#define I2C_RxNeask (I2C_SR1&0x40)
#define I2C_BTF (I2C_SR1&0x04)

#define I2C_BERR_ERR (I2C_SR2&0x01)
#define I2C_AF_ERR (I2C_SR2&0x04)

#define I2C_writebyte(x) I2C_DR=x;

void I2C_Init(void);
void I2C_Start(void);
void I2C_SendDAdr(u8 Add);
void I2C_SendDat(u8 data);
u8 I2C_RcvDat(void);
void I2C_WriteAbit(u8 addr,u8 data);
u8 I2C_ReadAbit(u8 addr);

#include "WS_I2C_SRC.H"

#endif /*_WS_I2C_h*/