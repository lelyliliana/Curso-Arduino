# Práctica — Caracterizar un sensor analógico

## Objetivo
Observar primero la señal cruda antes de inventar una conversión a unidades físicas.

## Procedimiento
1. Confirma alimentación y salida.
2. Lee ADC.
3. Registra mínimo y máximo observados.
4. Repite bajo condiciones diferentes.
5. Calcula promedio de varias muestras.
6. Consulta documentación para convertir a unidades, si el sensor lo permite.

## Promedio
```cpp
const int SENSOR = A0;
const int MUESTRAS = 10;

int leerPromedio() {
  long suma = 0;
  for (int i = 0; i < MUESTRAS; i++) {
    suma += analogRead(SENSOR);
  }
  return suma / MUESTRAS;
}
```

## Advertencia
Promediar reduce ciertas variaciones, pero también suaviza cambios rápidos.

## Reto
Compara lectura instantánea y promedio en Serial Plotter.
