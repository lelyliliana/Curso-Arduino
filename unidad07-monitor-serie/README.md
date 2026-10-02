# Unidad 07 — Monitor serie y diagnóstico

## Objetivo
Usar comunicación serial como herramienta de observación y depuración.

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(A0);
  Serial.print("A0 = ");
  Serial.println(valor);
  delay(200);
}
```

## Diagnóstico
Imprime:
- lecturas;
- estados;
- eventos;
- variables calculadas.

No conviertas cada programa en una avalancha de mensajes: imprime información útil para una pregunta concreta.

## Serial Plotter
Permite visualizar señales numéricas a lo largo del tiempo.

## Reto
Observa un potenciómetro en Serial Plotter y explica ruido, estabilidad y extremos.

## Qué sigue
Unidad 08 — Funciones y organización.
