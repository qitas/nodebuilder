/********************************************************************************************************
*
* File                : ws_onewire_src.h
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

#ifndef _WS_ONEWIRE_SRC_H_
#define _WS_ONEWIRE_SRC_H_

void _delay_us(u8 us)
{
	while(--us);
}

//-----复位-----
void resetOnewire(void) 
{
	OUT_DQ();
	CLR_DQ();
	_delay_us(750);
	SET_DQ();
	_delay_us(100);
	IN_DQ(); 
	//while(GET_DQ());
	while(!(GET_DQ()));
	SET_DQ();
}

//-----读数据-----
u8 rOnewire(void)
{
    u8 data=0,i=0;
    for(i=0;i<8;i++)
    {
		data=data>>1;
		OUT_DQ();
		CLR_DQ();
		IN_DQ();
		if(GET_DQ()) data|=0x80;
		else while(!(GET_DQ()));
		_delay_us(60);
	}
	return(data);
}
//-----写数据-----
void wOnewire(u8 data)
{
		u8 i=0;
		OUT_DQ();
    for(i=0;i<8;i++)
    {
			CLR_DQ();
			if(data&0x01)
			{
				SET_DQ();
			}
   	 	else
   	 	{
				CLR_DQ();
    	}
    	data=data>>1;
			_delay_us(60);  //65
			SET_DQ();
    }
}
#endif /*_WS_ONEWIRE_SRC_H_*/
