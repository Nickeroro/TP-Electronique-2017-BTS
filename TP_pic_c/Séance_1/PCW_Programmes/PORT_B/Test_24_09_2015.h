#include <16F876A.h>
#device ICD=TRUE
#device adc=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES XT                       //Crystal osc <= 4mhz for PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES PUT                      //Power Up Timer
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES DEBUG                    //Debug mode for use with ICD

#use delay(clock=2768000)

#use FIXED_IO( B_outputs=PIN_B5, PIN_B4, PIN_B3, PIN_B2, PIN_B1, PIN_B0)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)

