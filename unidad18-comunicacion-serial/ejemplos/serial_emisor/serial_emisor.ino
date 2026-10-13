#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial enlace(10, 11);
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  enlace.begin(9600);
  Serial.println(F("EMISOR: VAL numero seguido de LF"));
}
void loop() {
  if (millis() - ultimo >= 500) {
    ultimo = millis();
    enlace.print(F("VAL "));
    enlace.println(analogRead(A0));
  }
  while (enlace.available())
    Serial.write(enlace.read());
}
