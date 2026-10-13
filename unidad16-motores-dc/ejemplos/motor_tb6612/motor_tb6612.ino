#include <Arduino.h>
const byte IN1 = 7, IN2 = 8, PWM = 5, STBY = 4;
bool activo = false;
unsigned long inicio = 0;
void parar() {
  analogWrite(PWM, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(STBY, LOW);
  activo = false;
  Serial.println(F("Salida deshabilitada; esperar parada fisica"));
}
void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(STBY, OUTPUT);
  parar();
  Serial.println(F("f=adelante, r=atras, 0=parar; solo arrancar detenido"));
}
void loop() {
  if (activo && millis() - inicio >= 5000)
    parar();
  if (!Serial.available())
    return;
  char c = Serial.read();
  if (c == '0') {
    parar();
    return;
  }
  if (c != 'f' && c != 'r')
    return;
  if (activo) {
    Serial.println(F("Primero 0 y esperar parada real"));
    return;
  }
  digitalWrite(IN1, c == 'f');
  digitalWrite(IN2, c == 'r');
  digitalWrite(STBY, HIGH);
  analogWrite(PWM, 128);
  inicio = millis();
  activo = true;
  Serial.println(F("Marcha PWM=128; maximo 5 s"));
}
