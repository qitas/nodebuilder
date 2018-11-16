/********************************************************************************************************
*
* File                : ws_UAER1.h
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

#ifndef _WS_UART1_H
#define _WS_UART1_H

#define     true    1
#define     false   0

/*  declare const */
#define    rs_1k2bps         0x01
#define    rs_2k4bps         0x02
#define    rs_4k8bps         0x03
#define    rs_9k6bps         0x04
#define    rs_19k2bps        0x05
#define    rs_38k4bps        0x06                /* 串口速率 */
#define    rs_57k6bps        0x07
#define    rs_115k2bps       0x08                /* 串口速率 */

#define    mode_config       0x01
#define    mode_commun       0x00

#define    rs232_over_1k2bps 0x0a
#define    rs232_over_2k4bps 0x06
#define    rs232_over_4k8bps 0x04
#define    rs232_over_9k6bps 0x03
#define    rs232_over_19k2bps 0x02
#define    rs232_over_38k4bps 0x02
#define    rs232_over_57k6bps 0x02
#define    rs232_over_115k2bps 0x02



#define    buff_length          20
#define    point_top            buff_length-1
#define    point_bottom         0
#define     C_FIFO_Byte         0x14

u8 rs232_flag=0;
u8 rs232_temp;
extern u8 TxRFbuff[];
extern u8  TxRFbuffPointHead,TxRFbuffPointTail;
extern u8  RxRFbuffPointHead,RxRFbuffPointTail;
extern u8  time_rs232_over;
extern u8  time_rs232_over;
extern u8  time_rs232_back; 
extern u8  Format_rs232;
extern _Bool flag_rs232data_check;
/*
void Init_UART1(void)
{
		UART1_CR1=0x00;
		UART1_CR2=0x00;
		UART1_CR3=0x00;
		
		// 设置波特率，必须注意以下几点：
		//    (1) 必须先写BRR2
		//    (2) BRR1存放的是分频系数的第11位到第4位，
		//    (3) BRR2存放的是分频系数的第15位到第12位，和第3位
		//        到第0位
		// 例如对于波特率位9600时，分频系数=2000000/9600=208
		// 对应的十六进制数为00D0，BBR1=0D,BBR2=00


		UART1_BRR2=0x02;
		UART1_BRR1=0x68;
		
		UART1_CR2=0x2c;//允许接收，发送，开接收中断
		
}
*/
/***********************************************
函 数:	Init_Rs232
功 能:	初始化MCU串口状态
输 入:	/
输 出:	/
描 述:	/
***********************************************/

void    Init_Rs232(u8 rs_rate,u8 mode)
{
        UART1_CR1=0x00;
		    UART1_CR2=0x00;
		    UART1_CR3=0x00;
        
 	
        /* 串口速率设置 */
        switch(rs_rate)
        {
            case rs_1k2bps:
                 /* 1.2kbps */
                 UART1_BRR2=0x35;
		             UART1_BRR1=0x41;
                 time_rs232_back        = rs232_over_1k2bps;
                 break;
            case rs_2k4bps:
                 /* 2.4kbps */
                 UART1_BRR2=0x1b;
		             UART1_BRR1=0xa0;
                 time_rs232_back        = rs232_over_2k4bps;
                 break;
            case rs_4k8bps:
                 /* 4.8kbps */
                 UART1_BRR2=0x05;
		             UART1_BRR1=0xd0;
                 time_rs232_back        = rs232_over_4k8bps;
                 break;
            case rs_9k6bps:
                 /* 9.6kbps */
                 UART1_BRR2=0x02;
		             UART1_BRR1=0x68;
                 time_rs232_back        = rs232_over_9k6bps;
                 break;
            case rs_19k2bps:
                 /* 19.2kbps */
                 UART1_BRR2=0x01;
		             UART1_BRR1=0x34;
                 time_rs232_back        = rs232_over_19k2bps;
                 break;
            case rs_38k4bps:
                 /* 38.4kbps */
                 UART1_BRR2=0x01;
		             UART1_BRR1=0x1a;
                 time_rs232_back        = rs232_over_38k4bps;
                 break;
             case rs_57k6bps:
                 /* 56.6kbps */
                 UART1_BRR2=0x06;
		             UART1_BRR1=0x11;
                 time_rs232_back        = rs232_over_57k6bps;
                 break;

             case rs_115k2bps:
                 /* 115.2kbps */
                 UART1_BRR2=0x0b;
		             UART1_BRR1=0x08;
                 time_rs232_back        = rs232_over_115k2bps;
                 break;


            default:
                 /* 1.2kbps */
                 UART1_BRR2=0x35;
		             UART1_BRR1=0x41;
                 time_rs232_back        = rs232_over_1k2bps;
                 break;
        }
				
				
				
				
        if(mode == mode_config)
             UART1_CR2 = 0x0c;
        else
				{ 
				     UART1_CR2 = 0x2c;
						 
						 if(Format_rs232==2)
						 UART1_CR1=0x16;            //8o1
						 else if(Format_rs232==3)
						 UART1_CR1=0x14;            //8e1
             else
             UART1_CR1=0x00;            //8n1 
             						 
				}
        
       
}

/***********************************************
函 数:	Wait_Rs232_Tx
功 能:	/
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Wait_Rs232_Tx(void)
{
        //while(!(UCSR0A&0x20)){};
        //UCSR0A      |= 0x20;
				while((UART1_SR&0x40)==0x00);
}
/***********************************************
函 数:	Wait_Rs232_Rx
功 能:	/
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Wait_Rs232_Rx(void)
{
        time_rs232_over     = 0x03;
        //while((!(UCSR0A&0x80))&&(flag_config_para)&&(time_rs232_over)){};
        //UCSR0A             |= 0x80;
				while(((UART1_SR&0x20)==0x00)&&((PD_IDR&0x04)==0x00)&&(time_rs232_over));
}




void UART1_sendchar(u8 data)
{
		while((UART1_SR & 0x80)==0x00);
		UART1_DR=data;
}

@far @interrupt void UART1_Recv_IRQHandler (void)
{
	TxRFbuff[TxRFbuffPointHead++]  = UART1_DR;

  if(TxRFbuffPointHead > point_top)
  TxRFbuffPointHead = point_bottom;

  flag_rs232data_check = true;

  time_rs232_over      = time_rs232_back;
	return;
	
}

#endif /*_WS_UART3_H*/