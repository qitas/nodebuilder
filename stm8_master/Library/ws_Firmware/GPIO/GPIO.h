
#ifndef _GPIO_H_
#define _GPIO_H_

#define PA 0
#define PB 1
#define PC 2
#define PD 3
#define PE 4
#define PF 5
#define PG 6
#define PI 7

#define OUT 1
#define IN  0

u8 GPIO[8]=
{
  0x01,  /*!< Pin 0 selected */
  0x02,  /*!< Pin 1 selected */
  0x04,  /*!< Pin 2 selected */
  0x08,  /*!< Pin 3 selected */
  0x10,  /*!< Pin 4 selected */
  0x20,  /*!< Pin 5 selected */
  0x40,  /*!< Pin 6 selected */
  0x80   /*!< Pin 7 selected */
};

void Init_GPIO(u8 port,u8 io)
{
	if(io==1)
	{
		switch(port)
				{
					
					case 0: PA_DDR=0xff;PA_CR1=0xff;break;
					case 1: PB_DDR=0xff;PB_CR1=0xff;break; 
					case 2: PC_DDR=0xff;PC_CR1=0xff;break;  
					case 3: PD_DDR=0xff;PD_CR1=0xff;break;
					//case 4: PE_DDR=0xff;PE_CR1=0xff;break;
					/*case 5: PF_DDR=0xff;PF_CR1=0xff;break;
					case 6: PG_DDR=0xff;PG_CR1=0xff;break;
					case 7: PI_DDR=0xff;PI_CR1=0xff;break;*/
					default: break;
					
				}
	}
	else
	{
		switch(port)
				{
					
					case 0: PA_DDR=0x00;PA_CR2=0xff;break;
					case 1: PB_DDR=0x00;PB_CR2=0xff;break; 
					case 2: PC_DDR=0x00;PC_CR2=0xff;break;  
					case 3: PD_DDR=0x00;PD_CR2=0xff;break;
					//case 4: PE_DDR=0x00;PE_CR2=0xff;break;
					/*case 5: PF_DDR=0x00;PF_CR2=0xff;break;
					case 6: PG_DDR=0x00;PG_CR2=0xff;break;
					case 7: PI_DDR=0x00;PI_CR2=0xff;break;*/
					default: break;
					
				}
	}
}

void Send_led(u8 port)
{
	u8 i;
	for(i=0;i<8;i++)
		{
			switch(port)
			{
				case 0: PA_ODR=GPIO[i];break;
				case 1: PB_ODR=GPIO[i];break; 
				case 2: PC_ODR=GPIO[i];break;  
				case 3: PD_ODR=GPIO[i];break;
				//case 4: PE_ODR=GPIO[i];break;
				/*case 5: PF_ODR=GPIO[i];break;
				case 6: PG_ODR=GPIO[i];break;
				case 7: PI_ODR=GPIO[i];break;*/
				default: break;
			}
			delay_ms(500);
		}
}

#endif /*_GPIO_H_*/