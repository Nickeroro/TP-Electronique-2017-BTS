#include <Test_24_09_2015.h>
int LED1;

void main()
{
LED1 = 0x01;
   port_B_pullups(0xFF);

   while(TRUE)
   {
       Output_b(0x01);
   }
   
}
