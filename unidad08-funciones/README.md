# Unidad 08 — Funciones y organización del código

## Objetivo
Evitar sketches monolíticos y separar responsabilidades.

```cpp
const int LED = 8;

void encenderLed() {
  digitalWrite(LED, HIGH);
}

void apagarLed() {
  digitalWrite(LED, LOW);
}

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  encenderLed();
  delay(500);
  apagarLed();
  delay(500);
}
```

## Buenas prácticas
- nombres descriptivos;
- constantes para pines;
- una responsabilidad por función;
- evitar variables globales innecesarias;
- comentarios que expliquen decisiones, no lo obvio.

## Reto
Reorganiza un semáforo de tres LED usando funciones.

## Qué sigue
Unidad 09 — millis() y máquinas de estados.
