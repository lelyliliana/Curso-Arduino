# Soluciones desarrolladas de la Unidad 20

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Por qué no certifica la caída del riel

El divisor produce la mitad del riel y el ADC compara contra ese mismo riel. La cuenta conserva aproximadamente media escala aunque cambie la tensión. El cálculo final reintroduce 5.0 como supuesto y por eso parece confirmar su propio valor.

## 2. Corriente de arranque

Dimensiona fuente y driver considerando condiciones relevantes, incluidos picos y bloqueo según el actuador. Una lectura de corriente sin carga no garantiza operación con carga ni disipación admisible.

## 3. Separar potencia y lógica

Motor o servo utilizan el circuito de alimentación definido para ellos. La señal del Uno conserva una referencia de masa común cuando corresponde. No unas positivos de fuentes distintas por confundir masa común con alimentación común.

## Ejercicio resuelto

Con un riel hipotético de 4.5 V, el nodo entrega 2.25 V; la razón sigue siendo 0.5. El programa aún estima cerca de 5 V porque usa la constante 5.0. Necesitarías otra referencia de medición para evaluar esa caída.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
