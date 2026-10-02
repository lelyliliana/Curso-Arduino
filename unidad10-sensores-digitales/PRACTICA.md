# Práctica — Sensor digital como evento

## Objetivo
Leer una salida digital y separar tres etapas:
```text
sensor → interpretación → acción
```

## Antes de conectar
Consulta el módulo exacto:
- alimentación;
- GND;
- pin de salida;
- tensión de salida;
- si es activo en HIGH o LOW.

## Estrategia
Primero observa por Serial. Solo después controla un LED.

```cpp
const int SENSOR = 2;
const int LED = 8;

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lectura = digitalRead(SENSOR);
  Serial.println(lectura);

  bool evento = lectura == HIGH; // ajustar según módulo real
  digitalWrite(LED, evento);
}
```

## Diagnóstico
Si el comportamiento parece invertido, comprueba la lógica activa del módulo antes de invertir código arbitrariamente.

## Reto
Detecta cambios de estado y escribe por Serial solo cuando ocurra una transición.
