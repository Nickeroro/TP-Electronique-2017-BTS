#include <affectation_A_a_B.h>


int table[11]={192,249,164,176,153,146,131,248,128,144,127};
int unit, diz, cent, mill;
int val; 
int tempo;

void decomp_nb(int nombre)
{
if (nombre<10)
  {
    cent=0;
    diz=0;
    unit=nombre;
  }
   else
  {
     if (nombre<100)
     {
     cent=0;
     diz=nombre/10;
     unit=nombre-10*diz;
     }
   else
   {
   if (nombre<1000)
     {
     cent=nombre/100;
     diz=nombre-cent*100;
     diz=diz/10;
     unit=nombre-10*diz-100*cent;
     }
   }
  }
}

Void affichage(int affi, int chiffre)
{
output_a(affi);
output_b(table[chiffre]);
}

void main()
{port_b_pullups(0xFF);
tempo=5;
  while(TRUE)
    {
    val=148;
    decomp_nb(val);
    affichage(2,cent);
    delay_ms(tempo);
    affichage(4,diz);
    delay_ms(tempo);
    affichage(8,unit);
    delay_ms(tempo);
    }
  }
