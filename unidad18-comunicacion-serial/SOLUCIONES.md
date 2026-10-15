# Soluciones desarrolladas de la Unidad 18

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Números negativos o texto extra

Se rechazan. `leerTrama` recorre los caracteres, exige dígitos, limita longitud y después convierte. Evita aceptar silenciosamente solo el prefijo numérico de 12x.

## 2. Alcance de ACK

Confirma recepción y validación por el ejemplo. No confirma guardado, procedencia autenticada ni calidad del sensor. Cada garantía requeriría un mecanismo propio.

## 3. Velocidades

Las placas deben coincidir a 9600 en el enlace SoftwareSerial. El monitor de cada una coincide a 115200 con su Serial USB. No se necesita que enlaces independientes usen la misma velocidad.

## Recuperación de trama larga

El receptor reserva el terminador y activa descarte al superar el contenido disponible. Solo vuelve al estado inicial al recibir LF. Después una nueva `VAL 12` válida puede aceptarse. Una línea incompleta puede quedar pendiente; el diseño actual no tiene plazo de expiración de trama.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
