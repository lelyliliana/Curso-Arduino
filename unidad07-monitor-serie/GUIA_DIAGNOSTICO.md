# Guía de diagnóstico con Serial

## Pregunta primero
¿Qué quieres comprobar?

### ¿El sensor cambia?
Imprime lectura cruda.

### ¿La condición se cumple?
Imprime lectura y resultado lógico.

### ¿El estado cambia?
Imprime el nombre del estado solamente al producirse una transición.

### ¿El tiempo funciona?
Imprime millis() y marcas temporales.

## Serial Plotter
Para graficar, utiliza salidas numéricas consistentes. Evita mezclar texto arbitrario si dificulta el parser de la herramienta.

## Regla
Agregar Serial.println() en todas partes puede cambiar tiempos y ocultar el problema. Instrumenta una hipótesis concreta.
