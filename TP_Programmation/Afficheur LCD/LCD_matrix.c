
///////////////////////////////////////////////////////////////////////////
////                             LCD.C                                ////
////                 Driver for common LCD modules                     ////
////                                                                   ////
////  lcd_init()   Must be called before any other function.           ////
////                                                                   ////
////  lcd_putc(c)  Will display c on the next position of the LCD.     ////
////                     The following have special meaning:           ////
////                      \f  Clear display                            ////
////                      \n  Go to start of second line               ////
////                      \b  Move back one position                   ////
////                                                                   ////
////  lcd_gotoxy(x,y) Set write position on LCD (upper left is 1,1)    ////
////                                                                   ////
////                                                                   ////
////                                                                   ////
///////////////////////////////////////////////////////////////////////////

// As defined in the following structure the pin connection is as follows:
//     B5  enable
//     B4  rs
//     NC  rw
//     B0  D4
//     B1  D5
//     B2  D6
//     B3  D7
//



struct lcd_pin_map {
           int     data : 4;           // This structure is overlayed
           BOOLEAN rs;                 // on to an I/O port to gain
           BOOLEAN enable;             // access to the LCD pins.
           BOOLEAN unused1;            // The bits are allocated from
           BOOLEAN unused2;            // low order up.  ENABLE will
                                       // be pin B0.
        } lcd;


#byte lcd = 6                  // on to port B (at address 6)

#define set_tris_lcd(x) set_tris_b(x)

#define lcd_type 2           // 0=5x7, 1=5x10, 2=2 lines
#define lcd_line_two 0x40    // LCD RAM address for the second line


BYTE const LCD_INIT_STRING[4] = {0x20 , 0x2c, 0x06, 0x0c};
                             // These bytes need to be sent to the LCD
                             // to start it up.


                             // The following are used for setting
                             // the I/O port direction register.

struct lcd_pin_map const LCD_WRITE = {0,0,0,0,0}; // For write mode all pins are out



void lcd_send_nibble( BYTE n ) {
      lcd.data = n;
      delay_cycles(5);
      lcd.enable = 1;
      delay_cycles(5);
      lcd.enable = 0;
      delay_cycles(5);
}


void lcd_send_byte( BYTE address, BYTE n ) {

      lcd.rs = 0;
      delay_cycles(5);
      lcd.rs = address;
      delay_cycles(5);
      lcd.enable = 0;
      lcd_send_nibble(n >> 4);
      lcd_send_nibble(n & 0xf);
}


void lcd_init() {
    BYTE i;
    set_tris_lcd(LCD_WRITE);
    lcd.rs = 0;
    lcd.enable = 0;
    delay_ms(15);
    for(i=1;i<=3;++i) {
       lcd_send_nibble(3);
       delay_ms(5);
    }
    lcd_send_nibble(2);
    for(i=0;i<=3;++i)
       lcd_send_byte(0,LCD_INIT_STRING[i]);

}


void lcd_gotoxy( BYTE x, BYTE y) {
   BYTE address;

   if(y!=1)
     address=lcd_line_two;
   else
     address=0;
   address+=x-1;
   lcd_send_byte(0,0x80|address);
}

void lcd_putc( char c) {
   switch (c) {
     case '\f'   : lcd_send_byte(0,1);
                   delay_ms(2);
                                           break;
     case '\n'   : lcd_gotoxy(1,2);        break;
     case '\b'   : lcd_send_byte(0,0x10);  break;
     default     : lcd_send_byte(1,c);     break;
   }
}

