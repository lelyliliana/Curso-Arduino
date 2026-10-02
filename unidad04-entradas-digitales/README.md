# Unidad 04 — Entradas digitales y pulsadores

## Objetivo
Leer estados provenientes de un pulsador.

## INPUT_PULLUP
Arduino puede activar una resistencia interna pull-up.

Con esta configuración, un pulsador conectado entre pin y GND normalmente produce:
- sin pulsar: HIGH;
- pulsado: LOW.

```cpp
const int BOTON = 2;
const int LED = 8;

void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  bool pulsado = digitalRead(BOTON) == LOW;
  digitalWrite(LED, pulsado ? HIGH : LOW);
}
```

## Rebote
Un pulsador mecánico puede generar múltiples transiciones rápidas. Más adelante puedes aplicar debounce por software o hardware.

## Reto
Haz que cada pulsación cambie el estado del LED y permanezca así hasta la siguiente pulsación.

## Qué sigue
Unidad 05 — Señales analógicas y potenciómetro.
