# Soluciones desarrolladas de la Unidad 03

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Por qué escribir todas las salidas

Si solo enciendes el nuevo LED, el anterior puede seguir HIGH. `mostrar` expresa el estado completo: una salida encendida y las otras dos apagadas después de actualizar. Esto facilita contrastar cada fase con la tabla.

## 2. Fase apagada

Una alternativa concreta es fase 3 con los tres LED LOW durante 500 ms. Modifica el número de estados a cuatro, asigna esa duración y añade el mensaje APAGADO. La condición de cada LED ya es falsa en fase 3, pero debes explicar deliberadamente ese comportamiento. El nuevo ciclo nominal es 7500 ms.

## 3. Resistencias independientes

Cada rama conduce en condiciones propias. Una resistencia por rama permite calcular su corriente sin depender de otras ramas. Mantén 330 Ω como referencia y verifica polaridades antes de encender.

## Traza de la referencia

Arranque: rojo. Después de 3 s: verde. Después de otros 3 s: amarillo. Un segundo más tarde: rojo. El periodo de una fase no es el periodo del semáforo completo.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
