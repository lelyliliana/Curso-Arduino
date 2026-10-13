#include <Arduino.h>
#include <Wire.h>
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setWireTimeout(25000, true);
}
void loop() {
  if (millis() - ultimo < 3000)
    return;
  ultimo = millis();
  byte encontrados = 0;
  for (byte a = 1; a < 127; a++) {
    Wire.beginTransmission(a);
    byte e = Wire.endTransmission();
    if (e == 0) {
      Serial.print(F("ACK direccion 0x"));
      Serial.println(a, HEX);
      encontrados++;
    } else if (e == 4)
      Serial.println(F("Error de bus"));
  }
  Serial.print(F("Total="));
  Serial.println(encontrados);
}
