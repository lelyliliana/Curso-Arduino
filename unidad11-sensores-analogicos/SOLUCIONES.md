# Soluciones desarrolladas de la Unidad 11

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Intercambiar componentes

Con LDR arriba, más luz suele aumentar la tensión del nodo. Si la LDR se coloca hacia GND, el divisor cambia y más luz suele reducir la lectura. La interpretación depende del circuito concreto.

## 2. Coeficiente 0.1

Para anterior 500 y lectura 700: `500 + 0.1 × 200 = 520`. Con 0.2 produce 540. Un coeficiente menor conserva más memoria; no mejora automáticamente precisión ni detección de cambios rápidos.

## 3. Convertir a lux

Necesitas caracterización de la LDR y una referencia de iluminación adecuada, con condiciones documentadas. Esta práctica muestra cuentas y filtro; no lux.

## Solución de seguimiento

Con raw 700 sostenido y coeficiente 0.2, después de 540 llega 572 y luego 597.6. Si tu cálculo vuelve siempre a 540, probablemente reiniciaste el estado filtrado en cada vuelta. La variable global conserva la memoria del filtro.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
