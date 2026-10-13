#include "Logica.h"
#include <Arduino.h>
const byte LED = 5;
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}
void loop() {
  if (millis() - ultimo >= 100) {
    ultimo = millis();
    int raw = analogRead(A0);
    byte duty = Curso::pwmDesdeAdc(raw);
    analogWrite(LED, duty);
    Serial.print(F("ADC="));
    Serial.print(raw);
    Serial.print(F(" PWM="));
    Serial.println(duty);
  }
}
