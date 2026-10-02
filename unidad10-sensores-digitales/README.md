# Unidad 10 — Sensores digitales

## Objetivo
Integrar módulos que entregan estados discretos.

Ejemplos posibles: interruptores magnéticos, sensores de inclinación o módulos con salida digital.

## Método
1. Identifica alimentación y niveles lógicos.
2. Consulta pinout del módulo.
3. Comprueba si la salida es activa en HIGH o LOW.
4. Lee el pin.
5. Observa primero por Serial.
6. Después toma una acción.

```cpp
const int SENSOR = 2;

void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int estado = digitalRead(SENSOR);
  Serial.println(estado);
}
```

## Reto
Crea una alarma de estado con LED sin usar delay() para la lógica principal.

## Qué sigue
Unidad 11 — Sensores analógicos.
