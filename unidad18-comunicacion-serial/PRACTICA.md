# Práctica — Diseñar un protocolo serial

## Objetivo
Intercambiar mensajes que puedan validarse, no solo imprimir texto.

## Formato
Ejemplo:
```text
TEMP:25.4
HUM:68
LED:1
```

## Reglas
Define:
- inicio/fin de mensaje;
- separador;
- comandos permitidos;
- rangos;
- respuesta ante error.

## Ejemplo conceptual
```text
LED:1  → válido
LED:0  → válido
LED:9  → inválido
ABC:1  → comando desconocido
```

## Diagnóstico
Comprueba baud rate, finales de línea y si el receptor está leyendo mensajes completos o fragmentos.

## Reto
Diseña un protocolo para consultar sensor, cambiar umbral y controlar una salida. Documenta respuestas OK/ERROR.
