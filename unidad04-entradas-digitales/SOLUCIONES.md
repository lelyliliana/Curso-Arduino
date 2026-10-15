# Soluciones desarrolladas de la Unidad 04

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. LOW al pulsar

El contacto conecta D2 con GND. `INPUT_PULLUP` explica HIGH al soltar, sin resistencia externa en este circuito. Cambiar a INPUT sin añadir otra polarización deja de conservar ese contrato.

## 2. Por qué evitar una espera larga

Una pausa impide atender otras tareas durante ese tiempo. Además, esperar una cantidad fija después de la primera lectura no demuestra que la entrada no rebotó. La referencia recuerda el último cambio y exige estabilidad continuada.

## 3. Pulsación muy corta

Si LOW no se sostiene durante los 30 ms exigidos, no se acepta como estado estable. No se anuncia como evento perdido por accidente: está fuera de la duración mínima de esta referencia.

## Resultado de mantener

Tras confirmar la primera pulsación, `estable` y `crudo` son LOW. Ya no hay un cambio pendiente que aceptar, así que no se invierte otra vez el LED. La liberación estable prepara la siguiente pulsación; no la cuenta como pulsación adicional.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
