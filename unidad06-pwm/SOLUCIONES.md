# Soluciones desarrolladas de la Unidad 06

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Conversión de 512

`512 × 255 = 130560`. Dividido entre 1023 da 127 con división entera. El cálculo del sketch se realiza en 32 bits antes de convertir a byte.

## 2. Por qué D8 cambia la práctica

D8 no tiene PWM por hardware en el Uno R3. Un programa puede aceptar el pin sin producir una regulación equivalente. Verifica función, placa y temporizadores, no solamente que compile.

## 3. Media escala y brillo

PWM describe tiempo de activación. El LED y la percepción visual introducen otras relaciones. 128 no garantiza exactamente la mitad del brillo percibido ni la mitad de velocidad de un motor.

## Solución de la limitación

El `if` del desarrollo conserva 0..128 y recorta todo valor superior. Para ADC 1023 la función calcula inicialmente 255 y el recorte deja 128. Para ADC 512 calcula 127 y no cambia. Una escala proporcional a 128 daría aproximadamente 64 en el centro: son decisiones diferentes.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
