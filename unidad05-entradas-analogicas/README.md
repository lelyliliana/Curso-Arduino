# Unidad 05 — Señales analógicas y potenciómetro

## Objetivo
Leer una señal variable mediante el convertidor analógico-digital.

## Potenciómetro
Conecta extremos a alimentación y GND, y el terminal central a una entrada analógica.

## Lectura
En un Arduino Uno clásico, analogRead() devuelve normalmente valores de 0 a 1023.

```cpp
const int POT = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(POT);
  Serial.println(valor);
  delay(100);
}
```

## map()
Puede transformar un rango a otro, pero debes comprender los rangos y límites antes de usarlo.

## Reto
Convierte la lectura del potenciómetro a un porcentaje aproximado de 0 a 100.

## Qué sigue
Unidad 06 — PWM.
