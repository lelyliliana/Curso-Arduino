# Unidad 16 — Motores DC y etapa de potencia

## Objetivo
Comprender por qué un motor no debe conectarse directamente a un GPIO y cómo se separan control y potencia.

## Regla
**No conectes un motor DC directamente a un pin de Arduino.**

Los motores pueden demandar corriente elevada y generar transitorios inductivos.

## Arquitectura
```text
Arduino → etapa de control/potencia → motor
                 ↑
          alimentación adecuada
```

Pueden utilizarse drivers o puentes H apropiados al motor.

## Antes de conectar
Verifica:
- tensión nominal;
- corriente normal y de arranque/bloqueo;
- capacidad del driver;
- alimentación;
- masa común cuando corresponda;
- protección incorporada o requerida.

## Control
La dirección puede manejarse mediante un puente H y la velocidad mediante PWM si el driver lo permite.

## Reto
Diseña el diagrama lógico de un sistema que controle dirección y velocidad. Justifica fuente y driver según las especificaciones de un motor concreto.

## Qué sigue
Unidad 17 — Pantallas.
