#include <Arduino.h>
const byte LED = 8;
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Serial.println(F("Envia 1=ON, 0=OFF, ?=estado; ignora CR/LF"));
}
void loop() {
  if (!Serial.available())
    return;
  char c = Serial.read();
  if (c == '1' || c == '0') {
    digitalWrite(LED, c == '1');
    Serial.println(c == '1' ? F("ON") : F("OFF"));
  } else if (c == '?')
    Serial.println(digitalRead(LED) ? F("ON") : F("OFF"));
  else if (c != '\n' && c != '\r')
    Serial.println(F("Comando invalido; no cambio salida"));
}
