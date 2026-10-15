# Fuentes técnicas para seguir el desarrollo

[Curso](../README.md) · [Entorno](ENTORNO.md) · [Conexiones](CONEXIONES.md)

La referencia del curso es Uno R3 con ATmega328P. Las fórmulas y decisiones de los desarrollos se contrastan con los programas del curso; las características de otra placa o componente deben verificarse en su documentación.

| Tema | Fuente primaria | Uso en el curso |
|---|---|---|
| Placa, terminales y esquema | [Uno R3](https://docs.arduino.cc/hardware/uno-rev3/) | Identificación y recursos de la placa |
| ADC y potenciómetro | [Analog Read Serial](https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial/) | Entrada, referencia y códigos ADC |
| Salidas PWM | [Arduino: usar PWM](https://support.arduino.cc/hc/en-us/articles/9350537961500-Use-PWM-output-with-Arduino) | Pines disponibles y argumento de analogWrite |
| Implementación AVR | [ArduinoCore-avr 1.8.6](https://github.com/arduino/ArduinoCore-avr/tree/1.8.6) | Funciones y temporizadores de la referencia fijada |
| Servomotores | [Biblioteca Servo](https://docs.arduino.cc/libraries/servo/) | Órdenes, generación de pulsos y recursos compartidos |
| Pantalla paralela | [LiquidCrystal](https://docs.arduino.cc/libraries/liquidcrystal/) | Constructor, cursores e interfaz de cuatro bits |
| Sensor de temperatura | [TMP36 (Analog Devices)](https://www.analog.com/en/products/tmp36.html) | Offset, pendiente y patillas según encapsulado |
| Etapa de motor | [Carrier TB6612FNG (Pololu)](https://www.pololu.com/product/713) | Señales, alimentación y límites del carrier de referencia |

Un módulo comercial distinto puede alterar pinout, resistencias incorporadas y condiciones eléctricas. Un esquema funcional del curso no sustituye su ficha. No se atribuyen mediciones de laboratorio físico a estas fuentes ni a las comprobaciones de software.
