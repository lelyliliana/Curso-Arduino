#include "Logica.h"
#include <Arduino.h>
const byte TRIG = 7, ECHO = 6;
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  digitalWrite(TRIG, LOW);
  pinMode(ECHO, INPUT);
}
void loop() {
  if (millis() - ultimo < 100)
    return;
  ultimo = millis();
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  unsigned long tiempo = pulseIn(ECHO, HIGH, 25000UL);
  float cm;
  if (Curso::distanciaCm(tiempo, cm)) {
    Serial.print(F("cm aproximados="));
    Serial.println(cm, 1);
  } else
    Serial.println(F("SIN LECTURA VALIDA: timeout o fuera de rango"));
}
