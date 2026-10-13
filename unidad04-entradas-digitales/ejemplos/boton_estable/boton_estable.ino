#include "Logica.h"
#include <Arduino.h>
const byte BOTON = 2, LED = 8;
Curso::Boton boton;
bool salida = false;
void setup() {
  Serial.begin(115200);
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}
void loop() {
  if (boton.actualizar(digitalRead(BOTON), millis())) {
    salida = !salida;
    digitalWrite(LED, salida);
    Serial.println(salida ? F("ON") : F("OFF"));
  }
}
