# Soluciones desarrolladas de la Unidad 01

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Resistencia de 470 Ω

La tensión de la resistencia es 3 V. Entonces `I = 3 / 470 = 0.006383 A`, equivalente a 6.38 mA. `P = I² × 470 ≈ 0.0191 W`. No mezcles miliamperios con amperios al elevar al cuadrado.

## 2. LED sin resistencia

La relación corriente/tensión del LED no limita por sí sola la corriente a un valor adecuado. Una resistencia permite dimensionar cada rama. Dos LED en paralelo con una única resistencia no garantizan el mismo reparto de corriente.

## 3. ¿Es una medición?

No: el programa calcula a partir de constantes. Para demostrarlo, cambia la resistencia del modelo sin tocar hardware. Cambiará lo impreso aunque la placa no tenga un LED externo conectado.

## Solución del contraste

Pasar de 330 a 470 Ω reduce la corriente del modelo de 9.09 a 6.38 mA. La dirección del cambio es predecible; una relación exacta con brillo exige caracterizar el LED y la percepción. Una salida impresa con muchos decimales sigue siendo un cálculo con supuestos.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
