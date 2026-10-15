# Soluciones desarrolladas de la Unidad 19

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Identidad por dirección I2C

No. La dirección indica dónde respondió algo, pero varios modelos pueden compartirla. Para identidad, lee el registro documentado cuando exista y contrasta con la ficha.

## 2. SS D10 como salida

En el Uno AVR mantiene la configuración de controlador SPI cuando SS pudiera afectar ese modo. La referencia lo deja HIGH y no selecciona un esclavo, porque el ensayo es un retorno local MOSI→MISO.

## 3. Sensor SPI real

Necesitas conectar CS, SCK, MOSI/MISO según dispositivo y revisar alimentación, niveles, modo, frecuencia y comandos. Un puente no implementa registros ni validación de un sensor.

## Contraste de resultados

Con puente correcto se espera TX=A5 y RX=A5. Sin puente no se promete 00 ni FF: MISO está sin un origen definido. En I2C, ningún ACK obliga a revisar conexión y condiciones; no demuestra por sí solo que el chip esté averiado.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
