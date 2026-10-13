#include "Logica.h"
#include <Arduino.h>
const byte CONTACTO = 2, LED = 8;
Curso::Boton entrada;
bool estadoAnterior = true;
void setup() {
  Serial.begin(115200);
  pinMode(CONTACTO, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}
void loop() {
  entrada.actualizar(digitalRead(CONTACTO), millis());
  bool abierto = entrada.estable;
  digitalWrite(LED, abierto);
  if (abierto != estadoAnterior) {
    estadoAnterior = abierto;
    Serial.println(abierto ? F("CONTACTO ABIERTO") : F("CONTACTO CERRADO"));
  }
}
