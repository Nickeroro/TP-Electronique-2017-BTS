#include <16F88.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES INTRC_IO                 //internal RC osc, no CLOCKOUT
#FUSES DEBUG                    // debug mode for use with ICD
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(clock=4000000)

#use rs232(baud=9600,parity=N,xmit=PIN_B5,rcv=PIN_B2,bits=8,stream=PORT1)


int N_VAN0


void main()
{
   port_B_pullups(0xFF);
   setup_adc_ports(sAN0|sAN2);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_oscillator(OSC_4MHZ|OSC_INTRC);

set_adc_channel(sAN0);
   delay_us(100);
   
   while(TRUE)
   {
    N_VAN0=read_adc();
   
   }

}
