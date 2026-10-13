#include <Arduino.h>
void setup() {
  Serial.begin(115200);
  Serial.println(F("Curso Arduino: Uno R3, AVR, referencia de compilacion"));
  Serial.println(F("Sin perifericos: comprobar cable, puerto y monitor"));
}
void loop() {
  static unsigned long ultimo = 0;
  if (millis() - ultimo >= 1000) {
    ultimo = millis();
    Serial.print(F("Uptime ms="));
    Serial.println(millis());
  }
}
