/********************************************************************************************************
*
* File                : ws_onewire.h
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
#ifndef WS_ONEWIRE_H
#define WS_ONEWIRE_H
#include <system.h>

#define SET_DQ() sbi(PC_ODR,2)
#define CLR_DQ() cbi(PC_ODR,2)
#define OUT_DQ() sbi(PC_DDR,2)
#define DQ_PULL_UP() sbi(PC_CR1,2)
#define DQ_FLOATING() cbi(PC_CR1,2)

#define IN_DQ() cbi(PC_DDR,2)
#define DQ_PUSH_PULL() sbi(PC_CR1,2)
#define DQ_OPEN_DRAIN() cbi(PC_CR1,2);

#define GET_DQ() gbi(PC_IDR,2)

#include <ws_onewire_src.h>

#endif /*WS_ONEWIRE_H*/