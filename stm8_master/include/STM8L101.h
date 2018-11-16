/* STM8L101.h */

/* Copyright (c) 2003-2010 STMicroelectronics */

#ifndef __STM8L101__
#define __STM8L101__

/* STM8L101 */

	/* Check MCU name */
	#ifdef MCU_NAME
		#define STM8L101 1
		#if (MCU_NAME != STM8L101)
		#error "wrong include file STM8L101.h for chosen MCU!"
		#endif
	#endif

	#ifdef __CSMC__
		#define DEF_8BIT_REG_AT(NAME,ADDRESS) volatile unsigned char NAME @ADDRESS
		#define DEF_16BIT_REG_AT(NAME,ADDRESS) volatile unsigned int NAME @ADDRESS
	#endif

	#ifdef __RAISONANCE__
		#define DEF_8BIT_REG_AT(NAME,ADDRESS) at ADDRESS hreg NAME
		#define DEF_16BIT_REG_AT(NAME,ADDRESS) at ADDRESS hreg16 NAME
	#endif

/* Port A */
/*****************************************************************/

/* Port A data output latch register */
DEF_8BIT_REG_AT(PA_ODR,0x5000);

/* Port A input pin value register */
DEF_8BIT_REG_AT(PA_IDR,0x5001);

/* Port A data direction register */
DEF_8BIT_REG_AT(PA_DDR,0x5002);

/* Port A control register 1 */
DEF_8BIT_REG_AT(PA_CR1,0x5003);

/* Port A control register 2 */
DEF_8BIT_REG_AT(PA_CR2,0x5004);

/* Port B */
/*****************************************************************/

/* Port B data output latch register */
DEF_8BIT_REG_AT(PB_ODR,0x5005);

/* Port B input pin value register */
DEF_8BIT_REG_AT(PB_IDR,0x5006);

/* Port B data direction register */
DEF_8BIT_REG_AT(PB_DDR,0x5007);

/* Port B control register 1 */
DEF_8BIT_REG_AT(PB_CR1,0x5008);

/* Port B control register 2 */
DEF_8BIT_REG_AT(PB_CR2,0x5009);

/* Port C */
/*****************************************************************/

/* Port C data output latch register */
DEF_8BIT_REG_AT(PC_ODR,0x500a);

/* Port C input pin value register */
DEF_8BIT_REG_AT(PC_IDR,0x500b);

/* Port C data direction register */
DEF_8BIT_REG_AT(PC_DDR,0x500c);

/* Port C control register 1 */
DEF_8BIT_REG_AT(PC_CR1,0x500d);

/* Port C control register 2 */
DEF_8BIT_REG_AT(PC_CR2,0x500e);

/* Port D */
/*****************************************************************/

/* Port D data output latch register */
DEF_8BIT_REG_AT(PD_ODR,0x500f);

/* Port D input pin value register */
DEF_8BIT_REG_AT(PD_IDR,0x5010);

/* Port D data direction register */
DEF_8BIT_REG_AT(PD_DDR,0x5011);

/* Port D control register 1 */
DEF_8BIT_REG_AT(PD_CR1,0x5012);

/* Port D control register 2 */
DEF_8BIT_REG_AT(PD_CR2,0x5013);

/* Flash */
/*****************************************************************/

/* Flash control register 1 */
DEF_8BIT_REG_AT(FLASH_CR1,0x5050);

/* Flash control register 2 */
DEF_8BIT_REG_AT(FLASH_CR2,0x5051);

/* Flash Program memory unprotection register */
DEF_8BIT_REG_AT(FLASH_PUKR,0x5052);

/* Data EEPROM unprotection register */
DEF_8BIT_REG_AT(FLASH_DUKR,0x5053);

/* Flash in-application programming status register */
DEF_8BIT_REG_AT(FLASH_IAPSR,0x5054);

/* External Interrupt Control Register (ITC) */
/*****************************************************************/

/* External interrupt control register 1 */
DEF_8BIT_REG_AT(EXTI_CR1,0x50a0);

/* External interrupt control register 2 */
DEF_8BIT_REG_AT(EXTI_CR2,0x50a1);

/* External interrupt control register 3 */
DEF_8BIT_REG_AT(EXTI_CR3,0x50a2);

/* External interrupt status register 1 */
DEF_8BIT_REG_AT(EXTI_SR1,0x50a3);

/* External interrupt status register 2 */
DEF_8BIT_REG_AT(EXTI_SR2,0x50a4);

/* External interrupt port select register */
DEF_8BIT_REG_AT(EXTI_CONF,0x50a5);

/* Wait For Event (WFE) */
/*****************************************************************/

/* WFE control register 1 */
DEF_8BIT_REG_AT(WFE_CR1,0x50a6);

/* WFE control register 2 */
DEF_8BIT_REG_AT(WFE_CR2,0x50a7);

/* Reset (RST) */
/*****************************************************************/

/* Reset control register */
DEF_8BIT_REG_AT(RST_CR,0x50b0);

/* Reset status register */
DEF_8BIT_REG_AT(RST_SR,0x50b1);

/* Clock Control (CLK) */
/*****************************************************************/

/* Clock divider register */
DEF_8BIT_REG_AT(CLK_CKDIVR,0x50c0);

/* Peripheral clock gating register */
DEF_8BIT_REG_AT(CLK_PCKENR,0x50c3);

/* Configurable clock control register */
DEF_8BIT_REG_AT(CLK_CCOR,0x50c5);

/* Independent Watchdog (IWDG) */
/*****************************************************************/

/* IWDG Key Register */
DEF_8BIT_REG_AT(IWDG_KR,0x50e0);

/* IWDG Prescaler Register */
DEF_8BIT_REG_AT(IWDG_PR,0x50e1);

/* IWDG Reload Register */
DEF_8BIT_REG_AT(IWDG_RLR,0x50e2);

/* Auto Wake-Up (AWU) */
/*****************************************************************/

/* AWU Control/Status Register */
DEF_8BIT_REG_AT(AWU_CSR,0x50f0);

/* AWU asynchronous prescaler buffer register */
DEF_8BIT_REG_AT(AWU_APR,0x50f1);

/* AWU Timebase selection register */
DEF_8BIT_REG_AT(AWU_TBR,0x50f2);

/* Beeper (BEEP) */
/*****************************************************************/

/* BEEP Control/Status Register */
DEF_8BIT_REG_AT(BEEP_CSR,0x50f3);

/* Serial Peripheral Interface (SPI) */
/*****************************************************************/

/* SPI Control Register 1 */
DEF_8BIT_REG_AT(SPI_CR1,0x5200);

/* SPI Control Register 2 */
DEF_8BIT_REG_AT(SPI_CR2,0x5201);

/* SPI Interrupt Control Register */
DEF_8BIT_REG_AT(SPI_ICR,0x5202);

/* SPI Status Register */
DEF_8BIT_REG_AT(SPI_SR,0x5203);

/* SPI Data Register */
DEF_8BIT_REG_AT(SPI_DR,0x5204);

/* I2C Bus Interface (I2C) */
/*****************************************************************/

/* I2C control register 1 */
DEF_8BIT_REG_AT(I2C_CR1,0x5210);

/* I2C control register 2 */
DEF_8BIT_REG_AT(I2C_CR2,0x5211);

/* I2C frequency register */
DEF_8BIT_REG_AT(I2C_FREQR,0x5212);

/* I2C Own address register low */
DEF_8BIT_REG_AT(I2C_OARL,0x5213);

/* I2C Own address register high */
DEF_8BIT_REG_AT(I2C_OARH,0x5214);

/* I2C data register */
DEF_8BIT_REG_AT(I2C_DR,0x5216);

/* I2C status register 1 */
DEF_8BIT_REG_AT(I2C_SR1,0x5217);

/* I2C status register 2 */
DEF_8BIT_REG_AT(I2C_SR2,0x5218);

/* I2C status register 3 */
DEF_8BIT_REG_AT(I2C_SR3,0x5219);

/* I2C interrupt control register */
DEF_8BIT_REG_AT(I2C_ITR,0x521a);

/* I2C Clock control register low */
DEF_8BIT_REG_AT(I2C_CCRL,0x521b);

/* I2C Clock control register high */
DEF_8BIT_REG_AT(I2C_CCRH,0x521c);

/* I2C TRISE register */
DEF_8BIT_REG_AT(I2C_TRISER,0x521d);

/* Universal synch/asynch receiver transmitter (USART) */
/*****************************************************************/

/* USART Status Register */
DEF_8BIT_REG_AT(USART_SR,0x5230);

/* USART Data Register */
DEF_8BIT_REG_AT(USART_DR,0x5231);

/* USART Baud Rate Register 1 */
DEF_8BIT_REG_AT(USART_BRR1,0x5232);

/* USART Baud Rate Register 2 */
DEF_8BIT_REG_AT(USART_BRR2,0x5233);

/* USART Control Register 1 */
DEF_8BIT_REG_AT(USART_CR1,0x5234);

/* USART Control Register 2 */
DEF_8BIT_REG_AT(USART_CR2,0x5235);

/* USART Control Register 3 */
DEF_8BIT_REG_AT(USART_CR3,0x5236);

/* USART Control Register 4 */
DEF_8BIT_REG_AT(USART_CR4,0x5237);

/* 16-Bit Timer 2 (TIM2) */
/*****************************************************************/

/* TIM2 Control register 1 */
DEF_8BIT_REG_AT(TIM2_CR1,0x5250);

/* TIM2 Control register 2 */
DEF_8BIT_REG_AT(TIM2_CR2,0x5251);

/* TIM2 Slave Mode Control register */
DEF_8BIT_REG_AT(TIM2_SMCR,0x5252);

/* TIM2 External trigger register */
DEF_8BIT_REG_AT(TIM2_ETR,0x5253);

/* TIM2 Interrupt enable register */
DEF_8BIT_REG_AT(TIM2_IER,0x5254);

/* TIM2 Status register 1 */
DEF_8BIT_REG_AT(TIM2_SR1,0x5255);

/* TIM2 Status register 2 */
DEF_8BIT_REG_AT(TIM2_SR2,0x5256);

/* TIM2 Event Generation register */
DEF_8BIT_REG_AT(TIM2_EGR,0x5257);

/* TIM2 Capture/Compare mode register 1 */
DEF_8BIT_REG_AT(TIM2_CCMR1,0x5258);

/* TIM2 Capture/Compare mode register 2 */
DEF_8BIT_REG_AT(TIM2_CCMR2,0x5259);

/* TIM2 Capture/Compare enable register 1 */
DEF_8BIT_REG_AT(TIM2_CCER1,0x525a);

/* TIM2 Counter */
DEF_16BIT_REG_AT(TIM2_CNTR,0x525b);
/* Data bits High */
DEF_8BIT_REG_AT(TIM2_CNTRH,0x525b);
/* Data bits Low */
DEF_8BIT_REG_AT(TIM2_CNTRL,0x525c);

/* TIM2 Prescaler register */
DEF_8BIT_REG_AT(TIM2_PSCR,0x525d);

/* TIM2 Auto-reload register */
DEF_16BIT_REG_AT(TIM2_ARR,0x525e);
/* Data bits High */
DEF_8BIT_REG_AT(TIM2_ARRH,0x525e);
/* Data bits Low */
DEF_8BIT_REG_AT(TIM2_ARRL,0x525f);

/* TIM2 Capture/Compare register 1 */
DEF_16BIT_REG_AT(TIM2_CCR1,0x5260);
/* Data bits High */
DEF_8BIT_REG_AT(TIM2_CCR1H,0x5260);
/* Data bits Low */
DEF_8BIT_REG_AT(TIM2_CCR1L,0x5261);

/* TIM2 Capture/Compare register 2 */
DEF_16BIT_REG_AT(TIM2_CCR2,0x5262);
/* Data bits High */
DEF_8BIT_REG_AT(TIM2_CCR2H,0x5262);
/* Data bits Low */
DEF_8BIT_REG_AT(TIM2_CCR2L,0x5263);

/* TIM2 Break register */
DEF_8BIT_REG_AT(TIM2_BKR,0x5264);

/* TIM2 Output idle state register */
DEF_8BIT_REG_AT(TIM2_OISR,0x5265);

/* 16-Bit Timer 3 (TIM3) */
/*****************************************************************/

/* TIM3 Control register 1 */
DEF_8BIT_REG_AT(TIM3_CR1,0x5280);

/* TIM3 Control register 2 */
DEF_8BIT_REG_AT(TIM3_CR2,0x5281);

/* TIM3 Slave Mode Control register */
DEF_8BIT_REG_AT(TIM3_SMCR,0x5282);

/* TIM3 External trigger register */
DEF_8BIT_REG_AT(TIM3_ETR,0x5283);

/* TIM3 Interrupt enable register */
DEF_8BIT_REG_AT(TIM3_IER,0x5284);

/* TIM3 Status register 1 */
DEF_8BIT_REG_AT(TIM3_SR1,0x5285);

/* TIM3 Status register 2 */
DEF_8BIT_REG_AT(TIM3_SR2,0x5286);

/* TIM3 Event Generation register */
DEF_8BIT_REG_AT(TIM3_EGR,0x5287);

/* TIM3 Capture/Compare mode register 1 */
DEF_8BIT_REG_AT(TIM3_CCMR1,0x5288);

/* TIM3 Capture/Compare mode register 2 */
DEF_8BIT_REG_AT(TIM3_CCMR2,0x5289);

/* TIM3 Capture/Compare enable register 1 */
DEF_8BIT_REG_AT(TIM3_CCER1,0x528a);

/* TIM3 Counter */
DEF_16BIT_REG_AT(TIM3_CNTR,0x528b);
/* Data bits High */
DEF_8BIT_REG_AT(TIM3_CNTRH,0x528b);
/* Data bits Low */
DEF_8BIT_REG_AT(TIM3_CNTRL,0x528c);

/* TIM3 Prescaler register */
DEF_8BIT_REG_AT(TIM3_PSCR,0x528d);

/* TIM3 Auto-reload register */
DEF_16BIT_REG_AT(TIM3_ARR,0x528e);
/* Data bits High */
DEF_8BIT_REG_AT(TIM3_ARRH,0x528e);
/* Data bits Low */
DEF_8BIT_REG_AT(TIM3_ARRL,0x528f);

/* TIM3 Capture/Compare register 1 */
DEF_16BIT_REG_AT(TIM3_CCR1,0x5290);
/* Data bits High */
DEF_8BIT_REG_AT(TIM3_CCR1H,0x5290);
/* Data bits Low */
DEF_8BIT_REG_AT(TIM3_CCR1L,0x5291);

/* TIM3 Capture/Compare register 2 */
DEF_16BIT_REG_AT(TIM3_CCR2,0x5292);
/* Data bits High */
DEF_8BIT_REG_AT(TIM3_CCR2H,0x5292);
/* Data bits Low */
DEF_8BIT_REG_AT(TIM3_CCR2L,0x5293);

/* TIM3 Break register */
DEF_8BIT_REG_AT(TIM3_BKR,0x5294);

/* TIM3 Output idle state register */
DEF_8BIT_REG_AT(TIM3_OISR,0x5295);

/* 8-Bit  Timer 4 (TIM4) */
/*****************************************************************/

/* TIM4 Control register 1 */
DEF_8BIT_REG_AT(TIM4_CR1,0x52e0);

/* TIM4 Control register 2 */
DEF_8BIT_REG_AT(TIM4_CR2,0x52e1);

/* TIM4 Slave Mode Control register */
DEF_8BIT_REG_AT(TIM4_SMCR,0x52e2);

/* TIM4 Interrupt enable register */
DEF_8BIT_REG_AT(TIM4_IER,0x52e3);

/* TIM4 Status register 1 */
DEF_8BIT_REG_AT(TIM4_SR1,0x52e4);

/* TIM4 Event Generation register */
DEF_8BIT_REG_AT(TIM4_EGR,0x52e5);

/* TIM4 Counter */
DEF_8BIT_REG_AT(TIM4_CNTR,0x52e6);

/* TIM4 Prescaler register */
DEF_8BIT_REG_AT(TIM4_PSCR,0x52e7);

/* TIM4 Auto-reload register */
DEF_8BIT_REG_AT(TIM4_ARR,0x52e8);

/* Infra Red Interface (IR) */
/*****************************************************************/

/* Infra-red control register */
DEF_8BIT_REG_AT(IR_CR,0x52ff);

/* Comparators (CMP) */
/*****************************************************************/

/* Comparator control register */
DEF_8BIT_REG_AT(COMP_CR,0x5300);

/* Comparator status register */
DEF_8BIT_REG_AT(COMP_CSR,0x5301);

/* Comparator channel selection register */
DEF_8BIT_REG_AT(COMP_CCS,0x5302);

/*  Global configuration register (CFG) */
/*****************************************************************/

/* CFG Global configuration register */
DEF_8BIT_REG_AT(CFG_GCR,0x7f60);

/* Interrupt Software Priority Register (ITC) */
/*****************************************************************/

/* Interrupt Software priority register 1 */
DEF_8BIT_REG_AT(ITC_SPR1,0x7f70);

/* Interrupt Software priority register 2 */
DEF_8BIT_REG_AT(ITC_SPR2,0x7f71);

/* Interrupt Software priority register 3 */
DEF_8BIT_REG_AT(ITC_SPR3,0x7f72);

/* Interrupt Software priority register 4 */
DEF_8BIT_REG_AT(ITC_SPR4,0x7f73);

/* Interrupt Software priority register 5 */
DEF_8BIT_REG_AT(ITC_SPR5,0x7f74);

/* Interrupt Software priority register 6 */
DEF_8BIT_REG_AT(ITC_SPR6,0x7f75);

/* Interrupt Software priority register 7 */
DEF_8BIT_REG_AT(ITC_SPR7,0x7f76);

/* Interrupt Software priority register 8 */
DEF_8BIT_REG_AT(ITC_SPR8,0x7f77);

#endif /* __STM8L101__ */
