# Soluciones desarrolladas de la Unidad 08

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Función que cambia el LED

`representar` llama a `digitalWrite`. `decidir` únicamente devuelve un booleano y `adquirir` lee A0. Esa separación permite probar la regla sin usar la placa como fuente de datos.

## 2. Caso exacto 600

`600 >= 600` es verdadero, por tanto la salida se solicita encendida. La prueba con 600 distingue esta implementación de otra con `>`.

## 3. Oscilación alrededor del umbral

Con 599, 601, 599, 601 la referencia produce OFF, ON, OFF, ON. Para una banda 580..620, una regla con memoria puede conservar estado dentro de la banda. Un promedio y una histéresis resuelven aspectos distintos.

## Extensión desarrollada

Con umbral 700, las entradas 699, 700 y 701 deben dar false, true y true. Modifica la constante, no tres números aislados. Después repite con la adquisición real para comprobar que la composición conserva la misma frontera.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
