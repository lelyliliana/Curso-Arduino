# Unidad 12 — Distancia con ultrasonido

## Objetivo
Comprender medición de distancia mediante tiempo de vuelo usando un módulo ultrasónico compatible.

Los pines y niveles dependen del módulo. Verifica su documentación.

## Idea
1. Generar pulso de disparo.
2. Medir duración del eco.
3. Relacionar tiempo con velocidad aproximada del sonido.
4. Dividir el recorrido de ida y vuelta.

```text
distancia ≈ tiempo × velocidad / 2
```

## Limitaciones
Ángulo, material, temperatura, geometría y rango del sensor afectan la medición.

## Reto
Mide varias distancias conocidas, registra error y crea una alerta por umbral.

## Qué sigue
Unidad 13 — Temperatura y ambiente.
