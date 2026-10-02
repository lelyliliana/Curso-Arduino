# Práctica — Señales audibles por estados

## Antes de conectar
Identifica si el buzzer es activo o pasivo y su tensión/corriente. El comportamiento no es idéntico.

## Patrón conceptual
```text
NORMAL       → silencio
ADVERTENCIA  → beep corto periódico
ALARMA       → patrón distintivo
```

Para buzzer pasivo compatible:
```cpp
tone(8, 1000, 150);
```

## Diseño
Una alarma útil comunica estados diferentes; no basta con "hacer ruido".

## Reto
Implementa patrones no bloqueantes para tres estados utilizando millis().
