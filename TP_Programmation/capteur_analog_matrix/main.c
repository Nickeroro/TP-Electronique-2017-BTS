#include <main.h>
   int valeur;

void main()
{
   port_B_pullups(0xFF);
   setup_adc_ports(ALL_ANALOG);
   setup_adc(ADC_CLOCK_INTERNAL);

   
   set_adc_channel(1);
   delay_us(20);
   while(TRUE)
   {     
       valeur=read_adc();
       if (valeur>100)
          {
           output_b(0x01);
          }
       if (valeur<60)
          {
          output_b(0x00);
          }
   }
}

