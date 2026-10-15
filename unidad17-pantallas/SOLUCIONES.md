# Soluciones desarrolladas de la Unidad 17

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Backpack I2C

El programa no es intercambiable sin cambios. El montaje paralelo controla seis señales; un backpack introduce un expansor y direccionamiento. Necesitas identificarlo y usar una biblioteca compatible.

## 2. Espacios tras el número

La pantalla conserva caracteres anteriores hasta sobrescribirlos. Después de mostrar 1023, escribir solo 8 puede dejar 8023. Los espacios borran restos dentro de esa región sin limpiar el título.

## 3. Luz sin texto

Comprueba contraste VO, alimentación de lógica, RW a GND y correspondencia RS/E/D4..D7. Que encienda el backlight no prueba comunicación con el controlador.

## Ejercicio de porcentaje

Usa una muestra guardada y la conversión de la Unidad 05. Muestra, por ejemplo, `Nivel=100%` y después espacios suficientes para el máximo anterior. Prueba transición de 100 a 0 y verifica que no quede un porcentaje anterior pegado al nuevo.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
