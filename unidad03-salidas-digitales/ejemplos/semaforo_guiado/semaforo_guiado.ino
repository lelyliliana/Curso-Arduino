#include <Arduino.h>
const byte ROJO = 8, AMARILLO = 9, VERDE = 10;
byte fase = 0;
unsigned long ultimo = 0;
void mostrar() {
  digitalWrite(ROJO, fase == 0);
  digitalWrite(VERDE, fase == 1);
  digitalWrite(AMARILLO, fase == 2);
  Serial.println(fase == 0 ? F("ROJO") : fase == 1 ? F("VERDE") : F("AMARILLO"));
}
void setup() {
  Serial.begin(115200);
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  mostrar();
}
void loop() {
  unsigned long periodo = fase == 2 ? 1000UL : 3000UL;
  if (millis() - ultimo >= periodo) {
    ultimo = millis();
    fase = (fase + 1) % 3;
    mostrar();
  }
}
