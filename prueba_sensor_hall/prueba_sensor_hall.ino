// Prueba sensor Hall

const int HALLPin = 6;
const int LEDPin = 13;

void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(HALLPin, INPUT);
}

void loop() {
  if(digitalRead(HALLPin)==HIGH)
  {
    digitalWrite(LEDPin, HIGH);   
  }
  else
  {
    digitalWrite(LEDPin, LOW);
  }
}
