# Diseñar una máquina de estados

Antes del código, escribe los estados y transiciones.

## Semáforo
```text
VERDE --3 s--> AMARILLO --1 s--> ROJO --3 s--> VERDE
```

## Para cada estado define
- salidas;
- duración o evento de salida;
- siguiente estado.

## Ventaja
La lógica deja de estar escondida entre delays y se vuelve explícita.

## Ejercicio
Diseña primero en papel una alarma:

```text
NORMAL → ADVERTENCIA → ALARMA
```

Define qué evento produce cada transición y si existe camino de regreso.
