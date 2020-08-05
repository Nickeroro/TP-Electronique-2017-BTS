#include <main.h>
#define ENABLE_PIN B5
#define RS_PIN B4
#define Data4 B0
#define Data5 B1
#define Data6 B2
#define Data7 B3

#include <LCD_matrix.c>
 int Pression;
 
 
void main()
{
   
   port_B_pullups(0xFF);
   Pression = 32;
   lcd_init();
   lcd_putc("\f");
   printf(Lcd_putc, "Pression = %u", pression);
   
   
}

