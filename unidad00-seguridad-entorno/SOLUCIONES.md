# Soluciones desarrolladas de la Unidad 00

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. ¿Un LED de alimentación demuestra conexión de datos?

No. Puede recibir energía mediante un cable que no transmite datos. Comprueba que aparece el puerto y que puedes cargar el programa. Cada comprobación responde a una pregunta distinta.

## 2. ¿Qué velocidad se selecciona?

115200 baud porque coincide con `Serial.begin(115200)`. El número no se elige por preferencia: ambos extremos deben interpretar el enlace con la misma configuración.

## 3. ¿Por qué comenzar sin periféricos?

Aísla la comunicación y la carga. Después podrás distinguir un error del entorno de uno introducido por cableado o alimentación externa.

## Solución de la modificación

Con intervalo 2000 se imprime aproximadamente cada dos segundos. El primer mensaje periódico aparece cuando se cumple la primera espera, no inmediatamente al arrancar. El encabezado sí se envía en `setup`. Los tiempos de apertura del monitor no son el origen de `millis`; el origen es el reinicio de la placa.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
