# Soluciones desarrolladas de la Unidad 09

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Marcas independientes

`relojLed` describe la última inversión y `relojSensor` la última adquisición. Si el sensor actualizara la marca del LED cada 200 ms, podría impedir que el LED alcanzara sus 500 ms de espera.

## 2. ¿Hay paralelismo?

No: el procesador recorre un programa cooperativo. Las tareas se alternan rápidamente. Una operación bloqueante dentro de una afecta cuándo pueden atenderse las demás.

## 3. Medir retraso

Guarda tiempos observados consecutivos y resta. Compara con 200 ms nominales para el sensor. Distingue frecuencia de muestreo, tiempo de ejecución y error de observación del monitor.

## Tercera tarea

A 3000 ms nominales coinciden periodos de 200, 500 y 1500 ms. Con tres `if` separados pueden ejecutarse los tres. Cada tarea requiere su propia marca. Añadir una pausa de un segundo produciría retraso y pérdida de oportunidades de muestreo; no un registro del pasado.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
