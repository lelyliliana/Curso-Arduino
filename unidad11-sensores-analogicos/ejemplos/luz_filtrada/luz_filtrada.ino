#include <Arduino.h>
unsigned long ultimo = 0;
float filtrado = 0;
bool iniciado = false;
void setup() { Serial.begin(115200); }
void loop() {
  if (millis() - ultimo >= 100) {
    ultimo = millis();
    int raw = analogRead(A0);
    if (!iniciado) {
      filtrado = raw;
      iniciado = true;
    } else
      filtrado += 0.2f * (raw - filtrado);
    Serial.print(F("raw="));
    Serial.print(raw);
    Serial.print(F(" filtrado="));
    Serial.println(filtrado, 1);
  }
}
