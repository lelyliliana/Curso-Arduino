#include <Arduino.h>
void setup() {
  Serial.begin(115200);
  const float fuente = 5.0, caidaLed = 2.0, resistencia = 330.0;
  float corriente = (fuente - caidaLed) / resistencia;
  Serial.print(F("Modelo corriente mA="));
  Serial.println(corriente * 1000, 2);
  Serial.print(F("Modelo potencia resistencia W="));
  Serial.println(corriente * corriente * resistencia, 4);
  Serial.println(F("Modelo calculado; no es una medicion fisica"));
}
void loop() {}
