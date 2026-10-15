# Soluciones desarrolladas de la Unidad 22

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. ADC 500 después de oscuridad

La inversión da 523. Si oscuro ya era true, se conserva porque 523 es mayor que 423. Con modo habilitado se aplica PWM 128.

## 2. ADC 500 después de luz

Si oscuro era false, 523 no alcanza 623 y permanece false. El mismo dato puede conservar un estado distinto según la historia; esa es la función de la banda.

## 3. Botón mantenido

Una pulsación estable cambia el modo una sola vez. Para otra conmutación hace falta liberar estable y pulsar nuevamente. Deshabilitado mantiene PWM cero, aunque el sensor continúe actualizando oscuro.

## Fronteras exactas

raw 400 activa si estaba apagado. raw 600 libera si estaba encendido. Con raw entre 401 y 599 conserva la condición previa. Al rehabilitar se espera la próxima muestra para representar el resultado; no se supone encendido instantáneo.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
