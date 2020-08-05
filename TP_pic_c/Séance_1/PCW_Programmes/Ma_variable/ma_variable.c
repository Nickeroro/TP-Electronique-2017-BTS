#include <ma_variable.h>
int comptage ;

void main()


{
comptage = 1000;
   port_B_pullups(0xFF);

   while(comptage >= 50)
   {
       Output_b(0xFF);
       delay_ms (comptage);
       Output_b(0x00);
        delay_ms (comptage);
       comptage=comptage-25;
   }
   
}
