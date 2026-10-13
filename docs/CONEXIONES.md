# Conexiones de referencia (Uno R3)

[Entorno](ENTORNO.md) · [Laboratorios](../laboratorios/README.md)

Realiza **un montaje por vez**, desenergizado. La referencia es Uno R3 de lógica 5 V, no Uno R4 ni ESP32. Una etiqueta Dn corresponde al pin de la placa; no a la patilla n del encapsulado ATmega328P.

## Montajes de entrada/salida

| Componente | Conexión | Comprobación |
|---|---|---|
| LED externo | D8 →330 Ω →ánodo; cátodo →GND | polaridad y resistencia individual |
| LED PWM | D5 →330 Ω →ánodo; cátodo →GND | pin PWM del Uno R3 |
| Pulsador/reed seco | contacto entre D2 y GND | INPUT_PULLUP, libre HIGH/cerrado LOW |
| Potenciómetro 10 kΩ | extremos 5 V/GND; cursor A0 | identificar cursor central según componente |
| Divisor LDR |5 V →LDR →A0 →10 kΩ →GND | más luz suele aumentar cuenta en este orden |
| HC-SR04 compatible 5 V |VCC 5 V, GND, TRIG → D7, ECHO → D6 | no transferir ECHO 5 V directo a placa 3.3 V |
| TMP36 | alimentación 5 V/GND; VOUT → A0;100 nF cerca del sensor | identifica patillas en datasheet del encapsulado; no es LM35 |
| Piezo pasivo de señal |D8/GND (D7 en integrador) | corriente adecuada; no altavoz de baja impedancia |
| Divisor del propio riel 5 V |5 V →10 kΩ →A1 →10 kΩ →GND | no es medida independiente de fuente |

No uses todas estas conexiones simultáneamente: varias prácticas reutilizan pines. El diagrama que debes entregar surge de tu tabla de conexiones real.

## LCD16×2 compatible HD44780, interfaz paralela

| Pin LCD (nombre habitual) | Conexión |
|---|---|
|1 VSS |GND |
|2 VDD |5 V, si así lo especifica el módulo |
|3 VO |cursor de pot 10 kΩ de contraste; extremos 5 V/GND |
|4 RS |D12 |
|5 RW |GND (solo escritura) |
|6 E |D11 |
|7–10 D0–D3 |sin conectar en modo 4 bits |
|11 D4 |D5 |
|12 D5 |D4 |
|13 D6 |D3 |
|14 D7 |D2 |
|15 A /LED+ |5 V mediante limitación de corriente especificada por módulo |
|16 K /LED− |GND |

Si tu módulo tiene solo 4 pines y backpack I2C, **no corresponde a este montaje**. No apliques sin revisar su controlador/dirección/biblioteca. Para backlight sin limitación integrada, dimensiona resistencia según corriente/caída nominal de la ficha, no supongas conexión directa. Un segundo potenciómetro a A0 proporciona el valor de la práctica; no compartas su cursor con VO.

## Servo: referencia SG90 de 5 V, sin carga

| Señal | Conexión |
|---|---|
| Señal de control |D9 |
| Alimentación del servo |fuente 5 V separada adecuada a picos documentados |
| Masa del servo/fuente |GND común con Uno, si no hay aislamiento |
| Uno |USB |

No conectes el positivo de la fuente del servo al 5 V del Uno alimentado por USB. Identifica los cables por ficha, no solo por color. El nombre comercial SG90 no garantiza corriente ni pinout de cualquier copia. Arranca sin carga mecánica, posiciones moderadas y especificaciones verificadas.

## Motor con carrier TB6612FNG

| Pin carrier | Conexión |
|---|---|
| VCC lógica |5 V del Uno |
| VM potencia |fuente 6 V limitada y dimensionada para motor 6 V |
| GND |fuente motor y GND del Uno comunes |
| AIN1/AIN2 |D7/D8 |
| PWMA |D5 |
| STBY |D4 y pull-down 10 kΩ a GND si el carrier no lo proporciona |
| AO1/AO2 |terminales del motor |
| B no utilizado |según ficha del carrier, entradas en nivel definido |

Verifica tensión permitida, corriente de arranque/bloqueo, disipación y limitaciones del carrier. No deduzcas capacidad por un anuncio de amperios máximos. La deshabilitación del driver no confirma rotor detenido. No inviertas con rotor en marcha; comprueba parada real y usa montaje sin riesgo de movimiento.

## Serial entre dos Uno

| Cable | Conexión |
|---|---|
| A TX software D11 |B RX software D10 |
| B TX software D11 |A RX software D10 |
| Referencia |GND A↔GND B |
| Alimentación |USB propio en cada placa, sin unir 5 V |

SoftwareSerial 9600 y monitor USB 115200 son enlaces distintos. No conectar a puerto RS232 de tensiones positivas/negativas. Para otra placa verifica niveles antes de enlazar.

## Buses por separado

I2C: SDA A4 y SCL A5; dispositivo con niveles/alimentación compatibles y pull-ups adecuados. SPI loopback: puente D11 MOSI→D12 MISO; D10 OUTPUT/HIGH mantiene modo master, D13 es SCK. Loopback no necesita esclavo ni valida un sensor real.

## Conflictos a considerar al integrar

- Servo en Uno usa timer 1: PWM de D9/D10 se afecta aunque señal servo esté en otro pin.
- tone usa timer 2 en Uno AVR: puede afectar PWM D3/D11.
- SoftwareSerial usa temporización por software e interrupciones; no asumas que puede atender cualquier volumen simultáneamente con servo/otras cargas.
- LCD paralelo ocupa D2, D3, D4, D5, D11, D12; no sumes pulsador D2 o SPI sobre esos pines sin rediseñar.

El integrador 23 usa TMP36 A0, pulsador D2, LED D8 y piezo D7; no incluye Servo ni LCD para evitar prometer una integración que no implementa.

## Fuentes de referencia

- [Uno R3, pinout y esquemas](https://docs.arduino.cc/hardware/uno-rev3/).
- [TMP36, fabricante y ficha](https://www.analog.com/en/products/tmp36.html).
- [TB6612FNG carrier y documentación de su fabricante](https://www.pololu.com/product/713).
- [LiquidCrystal](https://docs.arduino.cc/libraries/liquidcrystal/).
- [Servo](https://docs.arduino.cc/libraries/servo/).

Estas referencias no sustituyen la documentación de un módulo con diseño diferente.
