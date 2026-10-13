#include "Trama.h"
#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial enlace(10, 11);
char buffer[20];
byte usados = 0;
bool descartar = false;
void setup() {
  Serial.begin(115200);
  enlace.begin(9600);
  Serial.println(F("RECEPTOR listo"));
}
void loop() {
  while (enlace.available()) {
    char c = enlace.read();
    if (c == '\r')
      continue;
    if (c == '\n') {
      buffer[usados] = '\0';
      int valor;
      if (!descartar && Curso::leerTrama(buffer, valor)) {
        Serial.print(F("VAL="));
        Serial.println(valor);
        enlace.print(F("ACK "));
        enlace.println(valor);
      } else
        Serial.println(F("TRAMA RECHAZADA"));
      usados = 0;
      descartar = false;
    } else if (!descartar) {
      if (usados < sizeof(buffer) - 1)
        buffer[usados++] = c;
      else
        descartar = true;
    }
  }
}
