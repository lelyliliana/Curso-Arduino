#include "Logica.h"
#include <Arduino.h>
const byte LED = 8, BOTON = 2, BUZZER = 7;
Curso::Boton boton;
bool habilitado = true, alerta = false;
unsigned long ultimo = 0;
void apagar() {
  digitalWrite(LED, LOW);
  noTone(BUZZER);
}
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
  apagar();
}
void loop() {
  if (boton.actualizar(digitalRead(BOTON), millis())) {
    habilitado = !habilitado;
    if (!habilitado)
      apagar();
    Serial.println(habilitado ? F("ACTIVO") : F("SILENCIADO"));
  }
  if (millis() - ultimo < 1000)
    return;
  ultimo = millis();
  float t;
  bool valido = Curso::temperaturaTmp36(analogRead(A0), 5.0, t);
  if (!valido) {
    alerta = false;
    apagar();
    Serial.println(F("DATO INVALIDO: salida OFF; revisar sensor"));
    return;
  }
  alerta = Curso::histeresisAlta(t, alerta, 30, 28);
  digitalWrite(LED, habilitado && alerta);
  if (habilitado && alerta)
    tone(BUZZER, 1200, 100);
  Serial.print(F("T="));
  Serial.print(t, 1);
  Serial.print(F(" alerta="));
  Serial.print(alerta);
  Serial.print(F(" habilitado="));
  Serial.println(habilitado);
}
