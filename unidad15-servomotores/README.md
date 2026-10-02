# Unidad 15 — Servomotores

## Objetivo
Controlar posición de un servomotor y comprender su alimentación.

Un servo puede requerir más corriente de la que conviene obtener de la placa. Para proyectos reales puede necesitar fuente externa apropiada y masa común.

## Biblioteca Servo
```cpp
#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
  servo.write(90);
}

void loop() {}
```

Los rangos mecánicos reales dependen del servo. No fuerces físicamente el mecanismo.

## Reto
Controla la posición mediante un potenciómetro y limita el rango a valores seguros para tu montaje.

## Qué sigue
Unidad 16 — Motores DC.
