# Soluciones desarrolladas de la Unidad 07

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Enviar 10

No solicita una magnitud diez. La primera vuelta con datos procesa `'1'` y enciende; otra procesa `'0'` y apaga. El resultado final es OFF. Para números completos hace falta definir una trama.

## 2. Consulta del estado

La respuesta ON del comando 1 anuncia la orden enviada al pin. La consulta ? lee además su nivel lógico, pero tampoco mide brillo ni corriente. Contrasta con el LED y el esquema cuando investigues una discrepancia.

## 3. Comando de ayuda

Una rama `else if (c == 'h')` puede imprimir `1=ON, 0=OFF, ?=estado`. Colócala antes de la rama que rechaza cualquier otro carácter. No añadas `digitalWrite` en esa rama. Prueba h con el LED previamente encendido y apagado.

## Comprobación de rechazo

La secuencia `1?x?0?` debe terminar OFF y conservar ON durante el rechazo de x. Un rechazo que apaga automáticamente la salida sería otra política; no corresponde al contrato de este programa.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
