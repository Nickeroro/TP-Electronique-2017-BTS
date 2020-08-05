/*
  Programme qui fait clignoter une led à une 
  fréquence de 0.5Hz
 */
const int led = 2; // La broche N° 2 sera connectée à la led
void setup() 
{                
  // Définir cette sortie en entrée ou sortie??
  
  pinMode(led, OUTPUT); //initialisation de la broche 2 comme étant une sortie   
}

void loop() //equivalent à void main {} en C (prog principal)
{
   digitalWrite(led, LOW); // écriture en sortie (broche 2) d'un état BAS
  //contenu de votre programme
  delay(2000);// on fait une pause du programme pendant 2000ms, soit 2 seconde
  digitalWrite(led, HIGH);
  delay(2000);
}
