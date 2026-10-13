#include <Arduino.h>
unsigned long ultimo = 0;
void setup() { Serial.begin(115200); }
void loop() {
  if (millis() - ultimo >= 200) {
    ultimo = millis();
    int raw = analogRead(A0);
    Serial.print(F("ADC="));
    Serial.print(raw);
    Serial.print(F(" porcentaje aproximado="));
    Serial.println(raw * 100L / 1023);
  }
}
