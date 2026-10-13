#include "Logica.h"
#include <Arduino.h>
const byte LED = 5, BOTON = 2;
Curso::Boton boton;
bool habilitado = true, oscuro = false;
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  analogWrite(LED, 0);
  pinMode(BOTON, INPUT_PULLUP);
}
void loop() {
  if (boton.actualizar(digitalRead(BOTON), millis())) {
    habilitado = !habilitado;
    Serial.println(habilitado ? F("AUTO") : F("DESHABILITADO"));
    if (!habilitado)
      analogWrite(LED, 0);
  }
  if (millis() - ultimo >= 100) {
    ultimo = millis();
    int raw = analogRead(A0);
    oscuro = Curso::histeresisAlta(1023 - raw, oscuro, 623, 423);
    analogWrite(LED, habilitado && oscuro ? 128 : 0);
    Serial.print(F("ADC="));
    Serial.print(raw);
    Serial.print(F(" oscuro="));
    Serial.println(oscuro);
  }
}
