#include <Arduino.h>
unsigned long ultimo = 0;
const float REFERENCIA = 5.0, FACTOR_DIVISOR = 2.0;
void setup() {
  Serial.begin(115200);
  Serial.println(F("Divisor 10k+10k en A1: solo verificar riel 5 V de esta placa"));
}
void loop() {
  if (millis() - ultimo >= 1000) {
    ultimo = millis();
    int raw = analogRead(A1);
    float tension = (raw + 0.5f) * REFERENCIA / 1024 * FACTOR_DIVISOR;
    Serial.print(F("Tension relativa V="));
    Serial.println(tension, 2);
    Serial.println(
        F("No es voltimetro independiente: ADC usa el mismo riel como referencia"));
  }
}
