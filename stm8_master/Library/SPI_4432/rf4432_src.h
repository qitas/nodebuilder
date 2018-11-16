
#include <ws_SPI.h>
#include <IA4432reg.h>

/*********************************************************************
**  Constant Declaration
*********************************************************************/
#define Uint8  u8
#define Uint16  u16

#define  RED_LED_ON   cbi(PD_ODR,6)
#define  RED_LED_OFF  sbi(PD_ODR,6)

#define  GREEN_LED_ON   cbi(PD_ODR,5)
#define  GREEN_LED_OFF  sbi(PD_ODR,5)

#define TIMEOUT     	85
#define t0hrel      	1000

u16  testv;

u8 ItStatus1,ItStatus2;
u8 length,temp8;




/************************************************************************
**  ByteSend
************************************************************************/
void ByteSend(Uint8 src)
{
	 
    Uint8 i;
    
		
		while(!(SPI_SR & 0x02));
		SPI_DR=src;
		while(!(SPI_SR & 0x01));
		i==SPI_DR;
		
		
	  
}

/************************************************************************
**  ByteRead
************************************************************************/
Uint8 ByteRead(void)
{
	
	
	u8 data;
	while(!(SPI_SR & 0x02));
	SPI_DR=0x55;
	
	while(!(SPI_SR & 0x01));
	data=SPI_DR;
	
	
	return data;
	
}




/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +
  + FUNCTION NAME: void SpiWriteRegister(U8 reg, U8 value)
  +
  + DESCRIPTION:   This function writes the registers 
  + 					
  + INPUT:			 U8 reg - register address   
  +					 U8 value - value write to register	
  +
  + RETURN:        None
  +
  + NOTES:         Write uses a Double buffered transfer
  +
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void SpiWriteRegister (u8 reg, u8 value)
{
   u8 i;
   u8 Temp_byte;
   
    cbi(PA_ODR,3);    //SCS = 0;     NSS = 0;                              
    Temp_byte = (reg|0x80);				//write data into the SPI register		
	  ByteSend(Temp_byte);
   
		Temp_byte = value;
		ByteSend(Temp_byte);
		
	  sbi(PA_ODR,3);    //SCS = 1;NSS = 1;    										
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +
  + FUNCTION NAME: U8 SpiReadRegister(U8 reg)
  +
  + DESCRIPTION:   This function reads the registers 
  + 					
  + INPUT:			 U8 reg - register address   
  +
  + RETURN:        SPI1DAT - the register content 
  +
  + NOTES:         none
  +
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
u8 SpiReadRegister (u8 reg)
{
    u8 i;
    u8 Temp_byte;
	  u8 Result;
	
	  cbi(PA_ODR,3);    //SCS = 0; NSS = 0;
		
	  Temp_byte = reg;				//write data into the SPI register
	  ByteSend(Temp_byte);	  
		Result=ByteRead();
		
	  sbi(PA_ODR,3);    //SCS = 1;NSS = 1;                            	
		return(Result);
   

}

/*********************************************************************
** initRF
*********************************************************************/

void init_IA4432(void)
{
    //init io pin
		
		
		sbi(PA_DDR,3);//SCS OUTPUT
		sbi(PA_CR1,3);
		cbi(PA_CR2,3);
		
		sbi(PC_DDR,5);//SCK OUTPUT
		sbi(PC_CR1,5);
		cbi(PC_CR2,5);
		
		sbi(PC_DDR,6);//SDIO OUTPUT
		sbi(PC_CR1,6);
		cbi(PC_CR2,6);
		
		cbi(PC_DDR,7);//GIO2 INPUT
		sbi(PC_CR1,7);
		cbi(PC_CR2,7);
		
		cbi(PD_DDR,3);//GIO1 WTR INPUT
		sbi(PD_CR1,3);
		cbi(PD_CR2,3);
			
    sbi(PA_ODR,3);
    cbi(PC_ODR,5);//SCK = 0;
    sbi(PC_ODR,6);//SDIO = 1;
		
		sbi(PD_DDR,5);//green_led OUTPUT
	  sbi(PD_CR1,5);
	  cbi(PD_CR2,5);
		
		sbi(PD_DDR,6);//red_led OUTPUT
	  sbi(PD_CR1,6);
	  cbi(PD_CR2,6);
		
	  cbi(PD_DDR,4);//key INPUT
	  sbi(PD_CR1,4);
	  cbi(PD_CR2,4);
		
		cbi(PD_DDR,3);//SET INPUT
	  sbi(PD_CR1,3);
	  cbi(PD_CR2,3);
		
		cbi(PB_DDR,4);//CKO INPUT
	  sbi(PB_CR1,4);
	  cbi(PB_CR2,4);
		
		SPI_Init();
		
		//Turn on the radio by pulling down the PWRDN pin
	//SDN = 0;  //no used
	//Wait at least 15ms befory any initialization SPI commands are sent to the radio
	// (wait for the power on reset sequence)
	delay_ms(5000);
	//for (temp8=0;temp8<15;temp8++)
	//{
		//for(delay=0;delay<10000;delay++);
	//}	 
	//read interrupt status registers to clear the interrupt flags and release NIRQ pin
	
	ItStatus1 = SpiReadRegister(0x03);													//read the Interrupt Status1 register
	ItStatus2 = SpiReadRegister(0x04);													//read the Interrupt Status2 register
    
	//SW reset   
   SpiWriteRegister(0x07, 0x80);															//write 0x80 to the Operating & Function Control1 register 
	
	//wait for POR interrupt from the radio (while the nIRQ pin is high)
	//while ( NIRQ == 1); 
  while((PD_IDR&0x04)==0x04) ; 
	//read interrupt status registers to clear the interrupt flags and release NIRQ pin
	ItStatus1 = SpiReadRegister(0x03);													//read the Interrupt Status1 register
	ItStatus2 = SpiReadRegister(0x04);													//read the Interrupt Status2 register
     
	//wait for chip ready interrupt from the radio (while the nIRQ pin is high)
	//while ( NIRQ == 1);
  while((PD_IDR&0x04)==0x04) ;   
	//read interrupt status registers to clear the interrupt flags and release NIRQ pin
	ItStatus1 = SpiReadRegister(0x03);													//read the Interrupt Status1 register
	ItStatus2 = SpiReadRegister(0x04);													//read the Interrupt Status2 register
						
							/*set the physical parameters*/
	//set the center frequency to 915 MHz
	//SpiWriteRegister(0x75, 0x75);															//write 0x75 to the Frequency Band Select register             
	//SpiWriteRegister(0x76, 0xBB);															//write 0xBB to the Nominal Carrier Frequency1 register
	//SpiWriteRegister(0x77, 0x80); 
 														//write 0x80 to the Nominal Carrier Frequency0 register
	
	SpiWriteRegister(0x75, 0x53);															//write 0x75 to the Frequency Band Select register             
	SpiWriteRegister(0x76, 0x64);															//write 0xBB to the Nominal Carrier Frequency1 register
	SpiWriteRegister(0x77, 0x00); 
	
	
	//set the desired TX data rate (9.6kbps)
	//SpiWriteRegister(0x6E, 0x4E);															//write 0x4E to the TXDataRate 1 register
	//SpiWriteRegister(0x6F, 0xA5);															//write 0xA5 to the TXDataRate 0 register
	//SpiWriteRegister(0x70, 0x2C);															//write 0x2C to the Modulation Mode Control 1 register
    
	
	//set the desired TX data rate (1.2kbps)
	SpiWriteRegister(0x2a, 0x14);	
	
	
	
	
	SpiWriteRegister(0x6E, 0x09);															//write 0x4E to the TXDataRate 1 register
	SpiWriteRegister(0x6F, 0xd5);															//write 0xA5 to the TXDataRate 0 register
	SpiWriteRegister(0x70, 0x2C);	
	
	
	
	//set the Tx deviation register (+-45kHz)
	//SpiWriteRegister(0x72, 0x48);	//(9.6kbps)														//write 0x48 to the Frequency Deviation register 
    SpiWriteRegister(0x72, 0x38);	//(1.2kbps)	

								/*set the modem parameters according to the exel calculator(parameters: 9.6 kbps, deviation: 45 kHz, channel filter BW: 102.2 kHz*/
	SpiWriteRegister(0x1C, 0x1b);															//write 0x1E to the IF Filter Bandwidth register		
	SpiWriteRegister(0x20, 0x83);															//write 0xD0 to the Clock Recovery Oversampling Ratio register		
	SpiWriteRegister(0x21, 0xc0);															//write 0x00 to the Clock Recovery Offset 2 register		
	SpiWriteRegister(0x22, 0x13);															//write 0x9D to the Clock Recovery Offset 1 register		
	SpiWriteRegister(0x23, 0xa9);															//write 0x49 to the Clock Recovery Offset 0 register		
	SpiWriteRegister(0x24, 0x00);															//write 0x00 to the Clock Recovery Timing Loop Gain 1 register		
	SpiWriteRegister(0x25, 0x03);															//write 0x24 to the Clock Recovery Timing Loop Gain 0 register		
	SpiWriteRegister(0x1D, 0x40);															//write 0x40 to the AFC Loop Gearshift Override register		
	SpiWriteRegister(0x1E, 0x0A);															//write 0x0A to the AFC Timing Control register		
	SpiWriteRegister(0x2A, 0x14);															//write 0x20 to the AFC Limiter register		
						
							/*set the packet structure and the modulation type*/
	//set the preamble length to 5bytes 
	SpiWriteRegister(0x34, 0x0A);															//write 0x0A to the Preamble Length register
	//set preamble detection threshold to 20bits
	SpiWriteRegister(0x35, 0x2A); 														//write 0x2A to the Preamble Detection Control  register

	//Disable header bytes; set variable packet length (the length of the payload is defined by the
	//received packet length field of the packet); set the synch word to two bytes long
	SpiWriteRegister(0x33, 0x02);															//write 0x02 to the Header Control2 register    
	
	//Set the sync word pattern to 0x2DD4
	SpiWriteRegister(0x36, 0x2D);															//write 0x2D to the Sync Word 3 register
	SpiWriteRegister(0x37, 0xD4);															//write 0xD4 to the Sync Word 2 register

	//enable the TX & RX packet handler and CRC-16 (IBM) check
	SpiWriteRegister(0x30, 0x8D);															//write 0x8D to the Data Access Control register
	//Disable the receive header filters
   SpiWriteRegister(0x32, 0x00 );														//write 0x00 to the Header Control1 register            
	//enable FIFO mode and GFSK modulation
	SpiWriteRegister(0x71, 0x63);															//write 0x63 to the Modulation Mode Control 2 register

											/*set the GPIO's according to the RF switch */
   SpiWriteRegister(0x0B, 0x12);															//write 0x12 to the GPIO2 Configuration(set the TX state)
	SpiWriteRegister(0x0C, 0x15);															//write 0x15 to the GPIO1 Configuration(set the RX state) 

											/*set the non-default Si443x registers*/
	//set  cap. bank
	SpiWriteRegister(0x09, 0xD7);															//write 0xD7 to the Crystal Oscillator Load Capacitance register
	// Set AGC Override1 Register
	SpiWriteRegister(0x69, 0x60);															//write 0x60 to the AGC Override1 register	

	//set tx power 20dbm max
	//SpiWriteRegister(0x6d, 0x1f);	 
	SpiWriteRegister(0x6d, 0x1e);	
	
	/*enable receiver chain*/
	SpiWriteRegister(0x07, 0x05);															//write 0x05 to the Operating Function Control 1 register
	//Enable two interrupts: 
	// a) one which shows that a valid packet received: 'ipkval'
	// b) second shows if the packet received with incorrect CRC: 'icrcerror' 
	SpiWriteRegister(0x05, 0x03); 														//write 0x03 to the Interrupt Enable 1 register
	SpiWriteRegister(0x06, 0x00); 														//write 0x00 to the Interrupt Enable 2 register
	//read interrupt status registers to release all pending interrupts
	ItStatus1 = SpiReadRegister(0x03);													//read the Interrupt Status1 register
	ItStatus2 = SpiReadRegister(0x04);													//read the Interrupt Status2 register
    //while((key1)&&(key2))
	//{
		/*enable receiver chain*/	    
		SpiWriteRegister(0x07, 0x05);	
		
		SpiWriteRegister(0x0d, 0xf4);	
		//while((key1)&&(key2));
		
	}
	
void sending(void)
{
	        //Wait for releasing the push button
			//while( PB == 0 );
			//disable the receiver chain (but keep the XTAL running to have shorter TX on time!)
			SpiWriteRegister(0x07, 0x01);													//write 0x01 to the Operating Function Control 1 register			

			//turn on the LED to show the packet transmission
			//TX_LED = 1; 
      RED_LED_ON;			
			/*SET THE CONTENT OF THE PACKET*/
			//set the length of the payload to 8bytes	
			SpiWriteRegister(0x3E, 8);														//write 8 to the Transmit Packet Length register		
			//fill the payload into the transmit FIFO
			SpiWriteRegister(0x7F, 0x42);													//write 0x42 ('B') to the FIFO Access register	
			SpiWriteRegister(0x7F, 0x55);													//write 0x55 ('U') to the FIFO Access register	
			SpiWriteRegister(0x7F, 0x54);													//write 0x54 ('T') to the FIFO Access register	
			SpiWriteRegister(0x7F, 0x54);													//write 0x54 ('T') to the FIFO Access register	
			SpiWriteRegister(0x7F, 0x4F);													//write 0x4F ('O') to the FIFO Access register	
			SpiWriteRegister(0x7F, 0x4E);													//write 0x4E ('N') to the FIFO Access register	
			SpiWriteRegister(0x7F, 0x31);													//write 0x31 ('1') to the FIFO Access register	
			SpiWriteRegister(0x7F, 0x0D);													//write 0x0D (CR) to the FIFO Access register	

			//Disable all other interrupts and enable the packet sent interrupt only.
			//This will be used for indicating the successfull packet transmission for the MCU
			SpiWriteRegister(0x05, 0x04);													//write 0x04 to the Interrupt Enable 1 register	
			SpiWriteRegister(0x06, 0x00);													//write 0x03 to the Interrupt Enable 2 register	
			//Read interrupt status regsiters. It clear all pending interrupts and the nIRQ pin goes back to high.
			ItStatus1 = SpiReadRegister(0x03);											//read the Interrupt Status1 register
			ItStatus2 = SpiReadRegister(0x04);											//read the Interrupt Status2 register

			/*enable transmitter*/
			//The radio forms the packet and send it automatically.
			SpiWriteRegister(0x07, 0x09);													//write 0x09 to the Operating Function Control 1 register

			/*wait for the packet sent interrupt*/
			//The MCU just needs to wait for the 'ipksent' interrupt.
			//while(NIRQ == 1);
			while((PD_IDR&0x04)==0x04) ; 
			//read interrupt status registers to release the interrupt flags
			ItStatus1 = SpiReadRegister(0x03);											//read the Interrupt Status1 register
			ItStatus2 = SpiReadRegister(0x04);											//read the Interrupt Status2 register
      delay_ms(20);
			//wait a bit for showing the LED a bit longer
			//for(delay = 0; delay < 10000;delay++);
			//for(delay = 0; delay < 60000;delay++);
			//turn off the LED
			//TX_LED = 0; 
			RED_LED_OFF;
			
			//after packet transmission set the interrupt enable bits according receiving mode
			//Enable two interrupts: 
			// a) one which shows that a valid packet received: 'ipkval'
			// b) second shows if the packet received with incorrect CRC: 'icrcerror' 
			SpiWriteRegister(0x05, 0x03); 												//write 0x03 to the Interrupt Enable 1 register
			SpiWriteRegister(0x06, 0x00); 												//write 0x00 to the Interrupt Enable 2 register
			//read interrupt status registers to release all pending interrupts
			ItStatus1 = SpiReadRegister(0x03);											//read the Interrupt Status1 register
			ItStatus2 = SpiReadRegister(0x04);											//read the Interrupt Status2 register

			/*enable receiver chain again*/
			SpiWriteRegister(0x07, 0x05);	   
	
}	
