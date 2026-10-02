# Unidad 22 — Proyecto: sistema automatizado

## Objetivo
Tomar decisiones a partir de sensores y controlar un actuador de manera segura.

## Arquitectura
```text
sensor → decisión/estado → actuador
             ↓
         diagnóstico
```

## Requisitos
- entrada real;
- al menos tres estados;
- temporización con millis();
- actuador apropiadamente controlado;
- modo seguro ante datos inválidos;
- monitorización;
- pruebas.

## Ejemplos de concepto
- barrera con servo;
- ventilación simulada;
- iluminación automática;
- alarma de proximidad.

## Seguridad
Si utilizas motor u otra carga, dimensiona etapa de potencia y fuente según especificaciones reales.

## Reto
Implementa una máquina de estados y documenta cada transición.

## Qué sigue
Unidad 23 — Proyecto final.
