#include <afficheur.h>
int led=0;
int lecture_A=8;
Void test()
{
          led = 0x01;
          while (led <= 0x80)
               {
               Output_b(led);
               delay_ms (250);
               Output_b(0x00);
               delay_ms (0);
               led=led*2;
               }  
}


void main()
{
   port_B_pullups(0xFF);
      While (true)
      {
       
       output_B(input_A());
       
       lecture_A=input_A() & 0x01;// lecture clavier
       switch (lecture_A)
            {
       case 0x01:test();
       break;
            }
   }
 }

