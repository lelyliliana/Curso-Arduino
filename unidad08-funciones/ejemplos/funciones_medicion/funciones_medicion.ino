#include <Arduino.h>
const byte LED = 8;
const int UMBRAL = 600;
unsigned long ultimo = 0;
int adquirir() { return analogRead(A0); }
bool decidir(int valor) { return valor >= UMBRAL; }
void representar(int valor, bool alerta) {
  digitalWrite(LED, alerta);
  Serial.print(F("ADC="));
  Serial.print(valor);
  Serial.print(F(" alerta="));
  Serial.println(alerta);
}
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}
void loop() {
  if (millis() - ultimo >= 200) {
    ultimo = millis();
    int valor = adquirir();
    representar(valor, decidir(valor));
  }
}
