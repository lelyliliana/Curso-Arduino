# Soluciones desarrolladas de la Unidad 23

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Silenciar no elimina la alerta

Cambia habilitado, que gobierna la representación. La temperatura se sigue adquiriendo y alerta conserva la lógica de histéresis. Al rehabilitar, la próxima muestra puede volver a activar salidas si la condición continúa.

## 2. Sensor desconectado

Puede producir una cuenta plausible. El rango de la función no equivale a detección confiable de desconexión. Una prueba de dato inválido debe identificar cómo se produjo y qué parte verificó.

## 3. Añadir potencia

Requiere driver, fuente, protecciones, montaje y pruebas adecuados, además de la decisión de control. El GPIO del integrador no alimenta motores ni cargas de red.

## Resolución del recorrido

Desde alerta OFF y habilitado: 29→sin alerta; 30→LED y tono; 29→continúa alerta; pulsación→silencio inmediato de salidas; otra pulsación→permite actuar en próxima muestra; 28→libera alerta. Un dato inválido reinicia alerta y apaga las salidas. A diferencia del monitoreo anterior, el LED no se utiliza aquí para indicar fallo.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
