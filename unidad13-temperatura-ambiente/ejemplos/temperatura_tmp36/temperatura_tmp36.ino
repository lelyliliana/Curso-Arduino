#include "Logica.h"
#include <Arduino.h>
const float REFERENCIA = 5.0;
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  Serial.println(F("TMP36: Vref aproximada; ajustar con medicion"));
}
void loop() {
  if (millis() - ultimo >= 1000) {
    ultimo = millis();
    float t;
    int raw = analogRead(A0);
    if (Curso::temperaturaTmp36(raw, REFERENCIA, t)) {
      Serial.print(F("temperatura_c="));
      Serial.println(t, 1);
    } else
      Serial.println(F("Lectura fuera del rango TMP36"));
  }
}
