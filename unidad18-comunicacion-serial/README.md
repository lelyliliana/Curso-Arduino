# Unidad 18 — Comunicación serial entre dispositivos

## Objetivo
Comprender transmisión de datos y diseñar mensajes simples.

## Conceptos
- baud rate;
- bytes;
- delimitadores;
- mensajes;
- parseo;
- errores de formato.

## Protocolo simple
```text
TEMP:25.4
LED:1
```

El receptor debe validar antes de actuar.

## Consideraciones
Los niveles eléctricos y puertos disponibles dependen de los dispositivos. No conectes interfaces con niveles incompatibles.

## Reto
Diseña un protocolo textual para transmitir temperatura, humedad y estado. Define cómo detectar mensajes inválidos.

## Qué sigue
Unidad 19 — I2C y SPI.
