#include <Arduino.h>
const byte LED = LED_BUILTIN;
bool encendido = false;
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}
void loop() {
  if (millis() - ultimo >= 1000) {
    ultimo = millis();
    encendido = !encendido;
    digitalWrite(LED, encendido);
    Serial.println(encendido ? F("ON") : F("OFF"));
  }
}
