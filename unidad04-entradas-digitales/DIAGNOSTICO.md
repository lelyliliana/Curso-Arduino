# Diagnóstico — Pulsador

## El valor parece invertido
Con INPUT_PULLUP:
- reposo suele ser HIGH;
- pulsado suele ser LOW.

## Cambia varias veces con una pulsación
Es probable que observes rebote mecánico.

## Siempre lee lo mismo
Comprueba:
- patas correctas del pulsador;
- orientación física;
- conexión a GND;
- pin del código;
- continuidad.

## Reto de diagnóstico
Imprime estado por Serial antes de controlar el LED. Separa primero el problema de lectura del problema de salida.
