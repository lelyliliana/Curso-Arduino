#include <Arduino.h>
#include <SPI.h>
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  SPI.begin();
}
void loop() {
  if (millis() - ultimo < 1000)
    return;
  ultimo = millis();
  SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));
  byte rx = SPI.transfer(0xA5);
  SPI.endTransaction();
  Serial.print(F("TX=A5 RX="));
  Serial.println(rx, HEX);
}
