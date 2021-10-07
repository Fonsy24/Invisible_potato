#include <LiquidCrystal.h>

#define HALLPin1 6
#define HALLPin2 5
#define BOBINAPin 9

bool sensor = false;
bool flag = true;
double t = 0.0, t0 = 0.0, taux = 0.0;


void setup() {
  Serial.begin(9600);

  pinMode(HALLPin1, INPUT);
  pinMode(HALLPin2, INPUT);
  pinMode(BOBINAPin, OUTPUT);
  digitalWrite(BOBINAPin, HIGH);
  delay(500);
  digitalWrite(BOBINAPin, LOW);
}

void loop() {
  if (digitalRead(HALLPin1) == LOW) {
    if (flag) {
      taux = millis();
      t = taux - t0;
      t0 = taux;
      Serial.print("Periodo:\t");
      Serial.println(2 * t / 1000, 1);
      flag = false;
    }
    sensor = true;
    digitalWrite(BOBINAPin, LOW);
    //Serial.println("Polo1");
  }
  if (digitalRead(HALLPin1) == HIGH && sensor) {
    delay(100);
    digitalWrite(BOBINAPin, HIGH);
    delay(50);
    digitalWrite(BOBINAPin, LOW);
    sensor = false;
    flag = true;
  }
  else {
    //Serial.println("Nada");
    digitalWrite(BOBINAPin, LOW);
  }
}
