
#define led_rouge 5// préciser sur quelle pin la connecter      
#define led_verte 3
#define led_bleu 6




void setup()
{
  pinMode(led_rouge, OUTPUT);    // Positionner la broche en sortie pour la led rouge
  pinMode(led_verte, OUTPUT); 
  pinMode (led_bleu, OUTPUT);   

analogWrite(led_rouge, 255);
analogWrite(led_verte, 25);
analogWrite(led_bleu, 0);
}

void loop()
{
  
}
