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
2741                     ; 17 main()
2741                     ; 18 {
2742                     	switch	.text
2743  004c               _main:
2747  004c               L3571:
2748                     ; 19 	while (1);
2750  004c 20fe          	jra	L3571
2763                     	xdef	_main
2764                     	xdef	_delay_us
2765                     	xdef	_delay_ms
2784                     	end
