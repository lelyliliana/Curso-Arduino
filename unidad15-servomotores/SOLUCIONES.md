# Soluciones desarrolladas de la Unidad 15

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. write(120)

Solicita una posición según la biblioteca. No mide 120 grados ni confirma llegada. Para comprobar posición necesitas observación o realimentación adecuada al objetivo.

## 2. Evitar extremos iniciales

El recorrido real depende del servo y de la mecánica. Un extremo puede forzar el tope. Comenzar en 60/120, o reducir a 80/100, permite una primera comprobación más controlada sin asumir un recorrido universal.

## 3. Reinicio del Uno

Revisa fuente independiente dimensionada para picos, conectores y masa común. No alimentes el servo desde un GPIO. El consumo en movimiento o bloqueo no se deduce de medirlo quieto.

## Solución de la secuencia

Primero se solicita 60; a los dos segundos 120; a los cuatro 60. Con órdenes 80/100 se conserva el ritmo, pero cambia el recorrido solicitado. El monitor anuncia una orden, no un sensor de posición. Documenta por separado lo solicitado y lo observado.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
