#include <16F876A.h>
#device ICD=TRUE
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES XT                       //Crystal osc <= 4mhz
#FUSES PUT                      //Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES DEBUG                    //Debug mode for use with ICD
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected

#use delay(clock=3276800)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)


int16 code,masque,valeur_bit;
int8 i,j;

void emis_0();
void emis_1();

void main()
{

   port_b_pullups(TRUE);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_spi(FALSE);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(VREF_LOW|-2);

   code=0x11;   // 0 0000 0001 0001

   output_low(PIN_B0);



      for(j=0;j<200;j++)

      {
         masque=0x1000;

         for(i=0;i<13;i++)
         {
            valeur_bit=code&masque;
            if(valeur_bit==0) emis_0();
                     else emis_1();
            masque=masque>>1;
         }
         output_low(PIN_B0);
         delay_ms(20);

      }
      while(1);


}


void emis_1()
{
output_low(PIN_B0);
set_timer0(0);
while(get_timer0()<69);
output_high(PIN_B0);
set_timer0(0);
while(get_timer0()<135);
}


void emis_0()
{
output_low(PIN_B0);
set_timer0(0);
while(get_timer0()<139);
output_high(PIN_B0);
set_timer0(0);
while(get_timer0()<65);
}






