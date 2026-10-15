# Soluciones desarrolladas de la Unidad 12

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Eco de 1000 µs

`1000 × 0.0343 / 2 = 17.15 cm`. La división entre dos evita contar ida y vuelta como si fueran solo distancia de ida. Imprimir una cifra decimal produce aproximadamente 17.1 o 17.2 según representación y redondeo; conserva el valor de cálculo como referencia aproximada.

## 2. Sin eco

Se informa lectura inválida. No significa distancia cero. Un fallo puede originarse en cableado, geometría, alcance o adquisición; el texto debe conservar esa incertidumbre.

## 3. ¿pulseIn es no bloqueante?

No. Espera hasta capturar el pulso o agotar su límite. El intervalo entre disparos y la duración de la espera son conceptos distintos.

## Solución del contraste

100 µs representa 1.715 cm, fuera del contrato de 2..400. 25000 µs representa 428.75 cm, también fuera. Tanto un dato recibido fuera de rango como un timeout deben evitar presentarse como medición válida, aunque sus causas sean distintas.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
