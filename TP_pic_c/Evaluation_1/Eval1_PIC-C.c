#include <Eval1_PIC-C.h>

int portb;

void main()
{
   port_B_pullups(0xFF);

   while(true)
  {
     portb=1;
     do
     {
     output_B (portb);
     delay_ms (500);
     
     portb=portb*2;
      if(portb==2)//  si variable portb �gal 2, afficher portb3 au lieu de portb2
          {
          portb=3;
          }
     }
     while((portb&0x3F) !=0);

  }
}
