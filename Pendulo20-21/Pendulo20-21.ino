#include <LiquidCrystal.h>

#define HALLPin1 5
#define HALLPin2 6
#define BOBINAPin 10

bool sensor = false;
bool flag = true;
double t = 0.0, t0 = 0.0, taux = 0.0;

LiquidCrystal lcd(13, 12, 11, 4, 3, 2, 7); //(RS,RW, E, D4,D5, D6, D7)

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);

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
      lcd.setCursor(0, 0);   // Pone el cursor en las coordenadas (0,0)
      lcd.clear();
      lcd.print("Periodo: ");
      lcd.setCursor(0, 1);
      lcd.print(2 * t / 1000, 2);
      Serial.println(2 * t / 1000, 1);
      flag = false;
    }
    sensor = true;
    digitalWrite(BOBINAPin, LOW);
    //Serial.println("Polo1");
  }
  if (digitalRead(HALLPin1) == HIGH && sensor) {
    digitalWrite(BOBINAPin, HIGH);
    delay(25);
    digitalWrite(BOBINAPin, LOW);
    sensor = false;
    flag = true;
  }
  else {
    //Serial.println("Nada");
    digitalWrite(BOBINAPin, LOW);
  }
}
