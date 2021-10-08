#include <LiquidCrystal.h>

#define HALLPin1 6
#define HALLPin2 5
#define BOBINAPin 9

bool sensor = false;
bool flag = true;
double t = 0.0, t0 = 0.0, taux = 0.0;
int tiempo;
int T;


void setup() {
  Serial.begin(9600);

  pinMode(HALLPin1, INPUT);
  pinMode(HALLPin2, INPUT);
  pinMode(BOBINAPin, OUTPUT);
  
}

void loop() {
  if (digitalRead(HALLPin2) == LOW) {

    tiempo = millis();

    while (digitalRead(HALLPin1) == HIGH){}

    T = millis() - tiempo;
    if(T>10000){
        digitalWrite(BOBINAPin, HIGH);
        delay(500);
        digitalWrite(BOBINAPin, LOW);
  }

    Serial.println(T);

    while (digitalRead(HALLPin1) == HIGH){}

    digitalWrite(BOBINAPin, HIGH);
    delay(T/2);
    digitalWrite(BOBINAPin, LOW);
  }
  
    
}
