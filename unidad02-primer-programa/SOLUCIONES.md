# Soluciones desarrolladas de la Unidad 02

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Trabajo de setup

Inicializa Serial, configura el pin como salida y solicita LOW. Se ejecuta una vez por arranque; RESET vuelve a iniciarlo. El estado guardado comienza en false y la primera inversión ocurre después de la espera.

## 2. Ciclo con intervalo de 250 ms

Con 250 ms entre transiciones, ON más OFF dura `250 ms + 250 ms = 500 ms`. Cambiar la condición a 500 produce un ciclo de 1000 ms. Con la referencia de 1000 por transición el ciclo completo es 2000 ms.

## 3. ¿Qué prueba ON en el monitor?

Prueba que se ejecutó una rama que anuncia el estado solicitado. No mide brillo ni continuidad eléctrica. Comparar la variable con una observación del LED añade evidencia diferente.

## Tabla de comprobación

| Intervalo de transición | Ciclo completo con tiempos iguales |
|---:|---:|
| 1000 ms | 2000 ms |
| 500 ms | 1000 ms |
| 250 ms | 500 ms |

La referencia utiliza la marca del momento observado; pequeños retrasos del recorrido pueden acumularse. No la presentes como generador de precisión.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
