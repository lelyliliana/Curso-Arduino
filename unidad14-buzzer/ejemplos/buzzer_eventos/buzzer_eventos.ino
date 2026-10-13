#include "Logica.h"
#include <Arduino.h>
const byte BOTON = 2, BUZZER = 8;
Curso::Boton boton;
void setup() {
  Serial.begin(115200);
  pinMode(BOTON, INPUT_PULLUP);
}
void loop() {
  if (boton.actualizar(digitalRead(BOTON), millis())) {
    tone(BUZZER, 1000, 150);
    Serial.println(F("Pulso sonoro 150 ms"));
  }
}
