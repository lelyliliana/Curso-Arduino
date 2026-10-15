# Soluciones desarrolladas de la Unidad 13

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Tensión a 25 °C

Despejamos `V = 0.5 + T / 100`. Para 25 da 0.75 V. El offset importa: aplicar solamente `V × 100` daría 75 °C, una respuesta equivocada aunque compile.

## 2. Usar un LM35

Requiere su propia ecuación, pinout y condiciones eléctricas. No conserves el offset del TMP36 por tener una apariencia parecida. La identidad del componente forma parte del programa de medición.

## 3. Desconectar el sensor

No garantiza que el ADC salga del rango plausible. Una entrada flotante puede producir una cuenta aceptable. Detectar desconexión de forma confiable requiere un diseño adicional y pruebas específicas.

## Resolución de una cuenta

Para raw 154: `(154.5 × 5 / 1024 - 0.5) × 100 ≈ 25.44 °C`. Un decimal impreso sería aproximadamente 25.4. La operación usa el centro del intervalo; no certifica la exactitud física del TMP36 ni de la referencia.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
