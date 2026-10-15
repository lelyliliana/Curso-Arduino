# Soluciones desarrolladas de la Unidad 05

[Laboratorio](LABORATORIO.md) · [Explicación paso a paso](DESARROLLO.md) · [Unidad](README.md)

Intenta primero los ejercicios del laboratorio. Compara el razonamiento y las condiciones, además del resultado.

## 1. Niveles y valor máximo

Hay 1024 códigos y el mayor es 1023 porque se comienza a contar en cero. Confundir cantidad con último índice conduce a errores de escala.

## 2. Lectura 512

`512 × 100 / 1023 = 50.048...`; con división entera se muestra 50. El sufijo L permite calcular el producto sin el desbordamiento de un int AVR.

## 3. Cursor desconectado

La entrada puede quedar flotante y recoger acoplamientos o carga residual. Un número aparentemente razonable no certifica posición. Desenergiza y revisa continuidad y referencia común.

## Solución con decimal

`Serial.println(raw * 100.0f / 1023.0f, 1);` muestra aproximadamente 50.0 para raw 512. La modificación cambia presentación y aritmética; no aumenta los 10 bits de resolución del convertidor. Registra por separado el código ADC y el porcentaje para conservar trazabilidad.

## Evidencia de tu práctica

Conserva predicción, cambio exacto y resultado observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Distingue cálculo, prueba de software y montaje físico. Una respuesta correcta en papel no sustituye una comprobación eléctrica.
