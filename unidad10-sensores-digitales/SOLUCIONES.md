# Soluciones desarrolladas de la Unidad 10

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. ¿Detecta quién abrió?

No. El contacto informa un cambio eléctrico; no incorpora identificación de personas. Tampoco mide distancia exacta al imán. La interpretación depende del componente y de cómo se instaló.

## 2. Sustituir por un botón

Permite comprobar niveles, estabilización y salida. No comprueba características magnéticas del reed. La evidencia debe nombrar qué componente se usó.

## 3. Detectar cable cortado

Este circuito de dos estados no distingue abierto intencional de interrupción del cable. Hace falta diseñar una supervisión adicional y probarla. No basta añadir una condición que vuelva a leer el mismo nivel.

## Caso de arranque

Si el contacto comienza abierto, `estadoAnterior` y `estable` valen true; no hay mensaje de cambio. El LED sí refleja HIGH al recorrer loop. Es coherente con un registro de transiciones, aunque un sistema que necesite estado inicial debería añadir ese requisito.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
