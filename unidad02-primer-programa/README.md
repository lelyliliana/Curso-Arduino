# Unidad 02 — Conoce Arduino y tu primer programa

## Objetivo
Comprender la estructura mínima de un sketch y cargar el primer programa.

## Placa
Identifica:
- microcontrolador;
- USB;
- alimentación;
- GND;
- 5 V / 3.3 V;
- pines digitales;
- entradas analógicas;
- LED integrado.

## setup()
Se ejecuta una vez al iniciar.

## loop()
Se repite mientras la placa esté funcionando.

## Primer programa
```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
```

## Qué observar
El LED integrado cambia de estado cada medio segundo.

## Nota sobre delay()
Es útil para este primer ejemplo, pero bloquea la ejecución. Más adelante aprenderás temporización con millis().

## Reto
Modifica los tiempos para crear un patrón reconocible.

## Qué sigue
Unidad 03 — Salidas digitales y LED.
