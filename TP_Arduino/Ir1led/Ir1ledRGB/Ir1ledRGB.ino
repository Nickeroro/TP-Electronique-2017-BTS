/*
 * pilotage de la led rouge par
 * la télécommande 
 
 * touche 1 pour commander la led rouge
 
 */

#include <IRremote.h>
// definition des touche télécommandes Oxygen 
//les codes ont été relevés par hyperterm

#define touche1 1637777535
#define touche2 1637755095 //01100001 10011110 00101000 11010111
#define touche3 1637761215 //01100001 10011110 01000000 10111111

#define led_rouge 2// préciser sur quelle pin la connecter      
#define led_verte 3
#define led_bleu 4



int RECV_PIN = 11;
int etatrouge ;
int etatvert ;
int etatbleu ;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();    // start le récepteur
  pinMode(led_rouge, OUTPUT);    // Positionner la broche en sortie pour la led rouge
  pinMode(led_verte, OUTPUT); 
  pinMode (led_bleu, OUTPUT);   
  
etatrouge=0;          // Initialiser la variable pour éteindre la led
etatvert=0;
etatbleu=0;
  
  digitalWrite(led_rouge, etatrouge);
  digitalWrite(led_verte, etatvert);
  digitalWrite(led_bleu, etatbleu);
//analogWrite(led_rouge, 255);
//analogWrite(led_verte, 255);
//analogWrite(led_bleu, 255);
  
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value,BIN);
    switch (results.value) 
    {
      case touche1:
      {
        Serial.println("rouge");
        etatrouge= !etatrouge; // Quelle est le role de cette ligne?
        digitalWrite(led_rouge, etatrouge);
      } 
      break;
      case touche2:
      {
        Serial.println("vert");
        etatvert= !etatvert; // Quelle est le role de cette ligne?
        digitalWrite(led_verte, etatvert);
      } 
      break;
      case touche3:
      {
        Serial.println("bleu");
        etatbleu= !etatbleu; // Quelle est le role de cette ligne?
        digitalWrite(led_bleu, etatbleu);
      } 
      break;
      
      
      
  }
    irrecv.resume(); // Receive the next value
  }
}
