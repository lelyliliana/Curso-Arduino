#include <Arduino.h>
unsigned long relojLed = 0, relojSensor = 0;
bool led = false;
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  unsigned long ahora = millis();
  if (ahora - relojLed >= 500) {
    relojLed = ahora;
    led = !led;
    digitalWrite(LED_BUILTIN, led);
  }
  if (ahora - relojSensor >= 200) {
    relojSensor = ahora;
    Serial.print(F("ADC="));
    Serial.println(analogRead(A0));
  }
}
