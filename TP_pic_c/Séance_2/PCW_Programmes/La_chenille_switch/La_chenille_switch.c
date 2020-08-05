#include <chenille.h>
int led=0;
int lecture_A=8;
Void sens_droit()
{
          led = 0x01;
          while (led <= 0x20)
               {
               Output_b(led);
               delay_ms (250);
               Output_b(0x00);
               delay_ms (0);
               led=led*2;
               }   
}

Void sens_gauche()
{
          led = 0x20;
          while (led >= 0x01)
               {
               Output_b(led);
               delay_ms (250);
               Output_b(0x00);
               delay_ms (0);
               led=led/2;       
               }
}


void main()
{
   port_B_pullups(0xFF);
      While (true)
   {
       lecture_A=input_A() & 0x03;// lecture clavier
       switch (lecture_A)
            {
       case 0x00:led=0x01;
       break;
       case 0x01:sens_droit ();
       break;
       case 0x02:sens_gauche();
            }
   }
 }

