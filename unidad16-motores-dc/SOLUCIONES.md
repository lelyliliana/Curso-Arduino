# Soluciones desarrolladas de la Unidad 16

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. PWM 128

Es un comando de ciclo de trabajo cercano a media escala, no una medición de velocidad. La velocidad depende de tensión, carga, pérdidas y motor. Sin realimentación no se garantiza una proporción exacta.

## 2. Pull-down en STBY

Define deshabilitación cuando el pin del Uno está en alta impedancia durante arranque o reinicio. El software todavía no ha ejecutado `parar` en ese momento. Verifica si el carrier ya lo incorpora.

## 3. Elegir fuente y driver

Considera tensión nominal, arranque, bloqueo, disipación y condiciones continuas del conjunto. El máximo de un anuncio comercial no es una garantía de operación permanente.

## Caso de inversión

Enviar r mientras activo produce rechazo. Después de 0 la variable permite otra marcha, pero la mecánica puede seguir girando. La referencia depende de que el operador espere parada real; no implementa un enclavamiento con sensor ni frenado verificado.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
