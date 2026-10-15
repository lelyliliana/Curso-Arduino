# Soluciones desarrolladas de la Unidad 14

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Buzzer activo

No se asume equivalente. El activo ya genera una frecuencia propia; el pasivo necesita una señal apropiada. Identifica consumo y ficha antes de usar el mismo circuito.

## 2. noTone

Detiene la señal generada por tone en el pin indicado. Es útil para cancelación explícita. Una duración finita también permite terminar sin que el programa deba esperar en un delay.

## 3. Límite temporal

Evita que una orden aislada mantenga sonido indefinidamente. En la referencia la duración es 150 ms por evento; mantener el botón no crea un evento cada vuelta.

## Contraste de parámetros

`1000, 300` conserva la frecuencia y duplica la duración respecto a la referencia. `1500, 150` cambia la frecuencia y conserva duración. Ninguno declara un nivel acústico calibrado. Una prueba que solo escucha sonido no comprueba exactamente milisegundos o hercios.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
