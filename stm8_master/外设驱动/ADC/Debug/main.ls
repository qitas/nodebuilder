   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Parser V4.8.32.1 - 30 Mar 2010
   3                     ; Generator V4.3.4 - 23 Mar 2010
2559                     ; 52 void delay_ms(u16 ms)
2559                     ; 53 {
2561                     	switch	.text
2562  0000               _delay_ms:
2564  0000 89            	pushw	x
2565  0001 88            	push	a
2566       00000001      OFST:	set	1
2569  0002 201b          	jra	L1561
2570  0004               L7461:
2571                     ; 57 				for(i=0;i<250;i++)
2573  0004 0f01          	clr	(OFST+0,sp)
2574  0006               L5561:
2577  0006 0c01          	inc	(OFST+0,sp)
2580  0008 7b01          	ld	a,(OFST+0,sp)
2581  000a a1fa          	cp	a,#250
2582  000c 25f8          	jrult	L5561
2583                     ; 59 				for(i=0;i<75;i++)
2585  000e 0f01          	clr	(OFST+0,sp)
2586  0010               L3661:
2589  0010 0c01          	inc	(OFST+0,sp)
2592  0012 7b01          	ld	a,(OFST+0,sp)
2593  0014 a14b          	cp	a,#75
2594  0016 25f8          	jrult	L3661
2595                     ; 61 				ms--;
2597  0018 1e02          	ldw	x,(OFST+1,sp)
2598  001a 1d0001        	subw	x,#1
2599  001d 1f02          	ldw	(OFST+1,sp),x
2600  001f               L1561:
2601                     ; 55 			while(ms!=0)
2603  001f 1e02          	ldw	x,(OFST+1,sp)
2604  0021 26e1          	jrne	L7461
2605                     ; 63 }
2608  0023 5b03          	addw	sp,#3
2609  0025 81            	ret
2652                     ; 65 void delay_us(u16 us)
2652                     ; 66 {
2653                     	switch	.text
2654  0026               _delay_us:
2656  0026 89            	pushw	x
2657  0027 88            	push	a
2658       00000001      OFST:	set	1
2661  0028 201b          	jra	L5171
2662  002a               L3171:
2663                     ; 70 				for(i=0;i<25;i++)
2665  002a 0f01          	clr	(OFST+0,sp)
2666  002c               L1271:
2669  002c 0c01          	inc	(OFST+0,sp)
2672  002e 7b01          	ld	a,(OFST+0,sp)
2673  0030 a119          	cp	a,#25
2674  0032 25f8          	jrult	L1271
2675                     ; 72 				for(i=0;i<7;i++)
2677  0034 0f01          	clr	(OFST+0,sp)
2678  0036               L7271:
2681  0036 0c01          	inc	(OFST+0,sp)
2684  0038 7b01          	ld	a,(OFST+0,sp)
2685  003a a107          	cp	a,#7
2686  003c 25f8          	jrult	L7271
2687                     ; 74 				us--;
2689  003e 1e02          	ldw	x,(OFST+1,sp)
2690  0040 1d0001        	subw	x,#1
2691  0043 1f02          	ldw	(OFST+1,sp),x
2692  0045               L5171:
2693                     ; 68 			while(us!=0)
2695  0045 1e02          	ldw	x,(OFST+1,sp)
2696  0047 26e1          	jrne	L3171
2697                     ; 76 }
2700  0049 5b03          	addw	sp,#3
2701  004b 81            	ret
2743                     ; 17 void Init_AD(void)
2743                     ; 18 {
2744                     	switch	.text
2745  004c               _Init_AD:
2749                     ; 19 		ADC_CSR=0x08;      //选择通道AIN8
2751  004c 35085400      	mov	_ADC_CSR,#8
2752                     ; 20 		ADC_CR2|=0x08;     //	数据排列,右对齐
2754  0050 72165402      	bset	_ADC_CR2,#3
2755                     ; 22 }
2758  0054 81            	ret
2803                     ; 24 void main(void)
2803                     ; 25 {
2804                     	switch	.text
2805  0055               _main:
2807  0055 88            	push	a
2808       00000001      OFST:	set	1
2811                     ; 27 		PB_DDR = 0xff;     
2813  0056 35ff5007      	mov	_PB_DDR,#255
2814                     ; 28 		PB_CR1 = 0xff;
2816  005a 35ff5008      	mov	_PB_CR1,#255
2817                     ; 30 		PD_DDR = 0xff;
2819  005e 35ff5011      	mov	_PD_DDR,#255
2820                     ; 31 		PD_CR1 = 0xff;
2822  0062 35ff5012      	mov	_PD_CR1,#255
2823                     ; 33 		Init_AD();
2825  0066 ade4          	call	_Init_AD
2827  0068               L1771:
2828                     ; 36 				ADC_CR1|=0x01;         //将CR1寄存器的最低位置1,开启AD转换
2830  0068 72105401      	bset	_ADC_CR1,#0
2831                     ; 37 				for(i=0;i<100;i++);    //延时一段时间，至少7uS，保证ADC模块的上电完成
2833  006c 0f01          	clr	(OFST+0,sp)
2834  006e               L5771:
2838  006e 0c01          	inc	(OFST+0,sp)
2841  0070 7b01          	ld	a,(OFST+0,sp)
2842  0072 a164          	cp	a,#100
2843  0074 25f8          	jrult	L5771
2844                     ; 38 				ADC_CR1|=0x01;         //再次将CR1寄存器的最低位置1,开启AD转换
2846  0076 72105401      	bset	_ADC_CR1,#0
2848  007a               L5002:
2849                     ; 40 				while((ADC_CSR & 0x80)!=0x80);  // 等待转换结束
2851  007a c65400        	ld	a,_ADC_CSR
2852  007d a480          	and	a,#128
2853  007f a180          	cp	a,#128
2854  0081 26f7          	jrne	L5002
2855                     ; 41 				PB_ODR=ADC_DRH;        //把高位用PB显示出来
2857  0083 5554045005    	mov	_PB_ODR,_ADC_DRH
2858                     ; 42 				PD_ODR=ADC_DRL;        //把低位用PD显示出来
2860  0088 555405500f    	mov	_PD_ODR,_ADC_DRL
2861                     ; 43 				ADC_CSR&=(~0x80);      //软件清零 转换结束 标志位
2863  008d 721f5400      	bres	_ADC_CSR,#7
2865  0091 20d5          	jra	L1771
2878                     	xdef	_main
2879                     	xdef	_Init_AD
2880                     	xdef	_delay_us
2881                     	xdef	_delay_ms
2900                     	end
