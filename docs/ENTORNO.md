# Entorno reproducible Arduino

[Curso](../README.md) · [Laboratorios](../laboratorios/README.md)

| Componente | Referencia |
|---|---|
| Placa |Uno R3, ATmega328P, 16 MHz, lógica 5 V |
| Perfil |`arduino:avr:uno` |
| Core Arduino AVR Boards |1.8.6 |
| Biblioteca Servo |1.3.0 |
| Biblioteca LiquidCrystal |1.0.7 |
| Monitor USB |115200 baud |
| Enlace SoftwareSerial |9600 baud |

Wire, SPI, SoftwareSerial y Arduino.h vienen con el core. Uno R4 tiene otro microcontrolador/core: no utilices esta tabla para afirmar que es el mismo entorno. Las versiones fijan una referencia reproducible; no son una exigencia de sistema operativo.

## Paso 1. Identificar placa y cable

Lee placa y chip, consulta pinout del fabricante y conecta solo USB de datos. Una placa encendida no demuestra conexión de datos. No instales drivers encontrados en sitios aleatorios; sigue instrucciones del fabricante del USB-serial real.

## Paso 2. Descargar el curso

En GitHub usa Code→Download ZIP y extrae a carpeta personal o clona el repositorio si ya usas Git. No abras el `.ino` directamente dentro del ZIP. Cada programa completo está en carpeta con su mismo nombre.

## Paso 3. Preparar Arduino IDE

Instala Arduino IDE 2.x desde sitio oficial para tu sistema. En gestor de placas busca **Arduino AVR Boards** e instala 1.8.6. Selecciona **Arduino Uno** y puerto correspondiente. No selecciones ESP32 ni Uno R4 para evitar un error de perfil.

## Paso 4. Bibliotecas

En gestor de bibliotecas instala **Servo 1.3.0** y **LiquidCrystal 1.0.7**. No instales LiquidCrystal_I2C para sustituir el LCD paralelo del curso: es otro montaje. Los sketches de Wire/SPI/SoftwareSerial no requieren una biblioteca externa de nombre parecido.

## Paso 5. Primera carga

Abre `unidad00-seguridad-entorno/ejemplos/diagnostico_usb/diagnostico_usb.ino`. Compila y revisa resultado; después carga. Abre monitor 115200 baud y pulsa RESET si no viste mensaje inicial. Completa diagnóstico antes de montar otro componente.

## Paso 6. Práctica por incrementos

Abre el laboratorio de la unidad y su tabla de conexiones. Comprueba materiales y montaje sin alimentación, carga y observa. No montes simultáneamente los 24 laboratorios. Los GPIO son señales, no fuentes de potencia para motores/servos.

## Verificación opcional con terminal

Para quien ya usa Arduino CLI, instala el programa desde [su documentación oficial](https://docs.arduino.cc/arduino-cli/). Desde una terminal ejecuta cada comando por separado:

```text
arduino-cli core update-index
```

```text
arduino-cli core install arduino:avr@1.8.6
```

```text
arduino-cli lib install Servo@1.3.0 LiquidCrystal@1.0.7
```

Abre terminal en raíz y ejecuta `python scripts/compilar.py` (macOS/Linux: python3; Windows: py -3 si ese es tu ejecutor). Compila los 26 programas de referencia, **sin cargar a placas**. El script usa carpeta temporal; no modifica tu montaje ni el firmware ya instalado.

Para comprobar solo una unidad usa `python scripts/compilar.py --unidad 12`. Opción y valor son dos argumentos. Esto permite diagnosticar sin esperar el resto.

## Antes de publicar tu proyecto

Registra placa, core, bibliotecas, pines, fuente, referencias y resultados. [VERIFICACION.md](VERIFICACION.md) distingue compilación de pruebas de hardware. [EVIDENCIAS.md](EVIDENCIAS.md) ofrece plantilla para tu entrega.

Fuentes: [ArduinoIDE](https://docs.arduino.cc/software/ide/), [Uno R3](https://docs.arduino.cc/hardware/uno-rev3/), [ArduinoCore-avr](https://github.com/arduino/ArduinoCore-avr).
