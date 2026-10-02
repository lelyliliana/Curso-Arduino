# Unidad 06 — PWM: brillo y control proporcional

## Objetivo
Utilizar modulación por ancho de pulso para controlar potencia promedio en cargas apropiadas.

PWM no convierte el pin en una fuente analógica real; conmuta rápidamente entre estados.

## Ejemplo LED
Utiliza un pin con capacidad PWM.

```cpp
const int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  for (int brillo = 0; brillo <= 255; brillo++) {
    analogWrite(LED, brillo);
    delay(5);
  }
}
```

## Potenciómetro → brillo
Lee 0–1023 y transforma a 0–255.

## Precaución
PWM desde un pin no habilita conectar cargas de corriente elevada. Motores y otras cargas requieren etapa de potencia.

## Reto
Controla brillo con potenciómetro y limita el rango mínimo/máximo.

## Qué sigue
Unidad 07 — Monitor serie y diagnóstico.
