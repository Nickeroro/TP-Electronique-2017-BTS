#include <affectation_A_a_B.h>

int digit; // variable qui s�lectionne un afficheur sur 4 
int table[11]={192,249,164,176,153,146,131,248,128,144,127};
int i; //variable index

void main()
{

   while(TRUE)
   {
          digit=1;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
            digit=2;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
            digit=3;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
            digit=4;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
            digit=5;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
            digit=6;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
             digit=7;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
             digit=8;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
             digit=9;
          for(i=0;i<11;i++)
            {
            output_a(digit);
            output_b(table[i]);
            delay_ms(50);
            }
   }

}
