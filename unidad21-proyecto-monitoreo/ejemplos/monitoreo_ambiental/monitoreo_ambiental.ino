#include "Logica.h"
#include <Arduino.h>
const byte LED = 8;
unsigned long ultimo = 0;
bool alerta = false;
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.println(
      F("TMP36: alta >=30 C, libera <=28 C; LED indica alerta o dato invalido"));
}
void loop() {
  if (millis() - ultimo < 1000)
    return;
  ultimo = millis();
  float t;
  if (!Curso::temperaturaTmp36(analogRead(A0), 5.0, t)) {
    alerta = false;
    digitalWrite(LED, HIGH);
    Serial.println(F("DATO INVALIDO; LED ON diagnostico, no temperatura 0"));
    return;
  }
  alerta = Curso::histeresisAlta(t, alerta, 30, 28);
  digitalWrite(LED, alerta);
  Serial.print(F("temperatura_c="));
  Serial.print(t, 1);
  Serial.print(F(" alerta="));
  Serial.println(alerta);
}
