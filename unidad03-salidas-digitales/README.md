# Unidad 03 — Salidas digitales y LED

## Objetivo
Controlar componentes mediante estados HIGH y LOW.

## Circuito
Pin digital → resistencia → LED → GND.

Verifica orientación del LED y resistencia antes de energizar.

## Código
```cpp
const int LED = 8;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
```

## Conceptos
- pinMode;
- OUTPUT;
- digitalWrite;
- HIGH/LOW;
- constantes para pines.

## Ejercicios
1. Cambia frecuencia.
2. Usa dos LED.
3. Crea un semáforo simple.

## Reto
Diseña una secuencia de tres LED y explica el estado de cada pin en cada momento.

## Qué sigue
Unidad 04 — Entradas digitales y pulsadores.
