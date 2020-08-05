#include <16F88.h>
#device adc=8

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES PUT                   	//Power Up Timer
#FUSES HS                    	//High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(clock=4000000)

#use rs232(baud=9600,parity=N,xmit=PIN_B5,rcv=PIN_B2,bits=8,stream=PORT1)

