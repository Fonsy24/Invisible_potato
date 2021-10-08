#include <LiquidCrystal.h>

#define HALLPin1 6
#define HALLPin2 5
#define BOBINAPin 9

bool sensor = false;
bool flag = true;
double t = 0.0, t0 = 0.0, taux = 0.0;
int randNumber = 0;

void setup() {
  Serial.begin(9600);

  pinMode(HALLPin1, INPUT);
  pinMode(HALLPin2, INPUT);
  pinMode(BOBINAPin, OUTPUT);
  randomSeed(analogRead(A0));

}

void loop() {
  if (digitalRead(HALLPin1) == LOW){
    randNumber = random(0,2);
    switch(randNumber){
      case 1:
      //Encender electroimán repeliendo
      break;
  
      case 2:
      //Encender electroimán atrayendo
      break;
  
      default:
      //No hacer nada y dejar pasar al péndulo
      break;
    }
  }
}
