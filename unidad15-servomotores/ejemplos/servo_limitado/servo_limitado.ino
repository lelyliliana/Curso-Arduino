#include <Arduino.h>
#include <Servo.h>
Servo servo;
unsigned long ultimo = 0;
bool posAlta = false;
void setup() {
  Serial.begin(115200);
  servo.attach(9);
  servo.write(60);
  Serial.println(F("Servo: alterna 60/120 grados cada 2 s; sin carga mecanica"));
}
void loop() {
  if (millis() - ultimo >= 2000) {
    ultimo = millis();
    posAlta = !posAlta;
    servo.write(posAlta ? 120 : 60);
    Serial.println(posAlta ? 120 : 60);
  }
}
