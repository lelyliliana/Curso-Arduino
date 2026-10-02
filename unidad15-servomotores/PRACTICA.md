# Práctica — Servo controlado por potenciómetro

## Seguridad eléctrica
Un servo puede demandar corrientes importantes, especialmente al arrancar o bajo carga. **No asumas que el pin 5 V/USB de la placa es una fuente adecuada para cualquier servo.**

Con fuente externa compatible puede requerirse referencia GND común entre fuente y Arduino para la señal, según la arquitectura.

## Señal
La biblioteca Servo genera la señal de control.

```cpp
#include <Servo.h>

Servo miServo;
const int POT = A0;

void setup() {
  miServo.attach(9);
}

void loop() {
  int lectura = analogRead(POT);
  int angulo = map(lectura, 0, 1023, 10, 170);
  miServo.write(angulo);
  delay(15);
}
```

## Límites
El rango mecánico real depende del servo y del mecanismo. Evita forzar topes.

## Diagnóstico
Si Arduino se reinicia al mover el servo, investiga alimentación antes de modificar el programa.

## Reto
Define límites configurables y evita movimientos fuera del rango seguro del mecanismo.
