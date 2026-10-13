# Curso de Arduino desde cero

**[Comenzar el curso: Unidad 00 — Seguridad, materiales y entorno](unidad00-seguridad-entorno/README.md)**

Puedes leer las lecciones aquí sin conocer GitHub. Al terminar cada unidad, usa **Siguiente unidad** para avanzar; **Unidad anterior** y **Volver al índice** te permiten regresar.

[Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

**Versión 1.1 (laboratorios de referencia)**

Curso abierto para aprender **electrónica, programación y prototipado con Arduino** mediante prácticas progresivas y proyectos.

La ruta comienza con seguridad, electricidad básica y preparación del entorno, y avanza hacia entradas y salidas digitales y analógicas, sensores, actuadores, comunicación, organización del código y proyectos integradores.

## Comenzar con un montaje reproducible

Consulta el [entorno fijado](docs/ENTORNO.md), las [tablas de conexiones](docs/CONEXIONES.md) y los [24 laboratorios con 26 programas completos](laboratorios/README.md). Cada unidad enlaza su práctica ysoluciones. Revisa [qué se verificó](docs/VERIFICACION.md) y registra tus resultados físicos.

## Objetivo

Al finalizar podrás:

- reconocer los componentes principales de una placa Arduino;
- montar circuitos básicos de forma segura;
- interpretar voltaje, corriente, resistencia y potencia a nivel introductorio;
- utilizar protoboard, resistencias, LED, pulsadores y potenciómetros;
- programar entradas y salidas digitales;
- leer señales analógicas;
- generar PWM;
- trabajar con sensores y actuadores;
- utilizar monitor serie;
- organizar programas mediante funciones y estados;
- comprender temporización sin bloquear innecesariamente el programa;
- integrar pantallas, motores y otros módulos;
- diseñar, probar y documentar prototipos propios.

## Hardware de referencia

Los ejemplos utilizan principalmente una placa compatible con **Arduino Uno**. Muchos de los conceptos son transferibles a otras placas, verificando siempre sus especificaciones.

> Antes de conectar un componente, verifica siempre su voltaje, corriente requerida, polaridad y forma correcta de conexión.

## Ruta de aprendizaje

### Nivel 1 — Preparación y fundamentos
- [Unidad 00 — Seguridad, materiales y entorno](unidad00-seguridad-entorno/)
- [Unidad 01 — Electricidad y electrónica básica](unidad01-electronica-basica/)
- [Unidad 02 — Conoce Arduino y tu primer programa](unidad02-primer-programa/)

### Nivel 2 — Entradas y salidas
- [Unidad 03 — Salidas digitales y LED](unidad03-salidas-digitales/)
- [Unidad 04 — Entradas digitales y pulsadores](unidad04-entradas-digitales/)
- [Unidad 05 — Señales analógicas y potenciómetro](unidad05-entradas-analogicas/)
- [Unidad 06 — PWM: brillo y control proporcional](unidad06-pwm/)

### Nivel 3 — Programación aplicada
- [Unidad 07 — Monitor serie y diagnóstico](unidad07-monitor-serie/)
- [Unidad 08 — Funciones y organización del código](unidad08-funciones/)
- [Unidad 09 — Tiempo con millis() y máquinas de estados](unidad09-tiempo-estados/)

### Nivel 4 — Sensores
- [Unidad 10 — Sensores digitales](unidad10-sensores-digitales/)
- [Unidad 11 — Sensores analógicos](unidad11-sensores-analogicos/)
- [Unidad 12 — Distancia con ultrasonido](unidad12-ultrasonido/)
- [Unidad 13 — Temperatura y ambiente](unidad13-temperatura-ambiente/)

### Nivel 5 — Actuadores e interfaces
- [Unidad 14 — Buzzer y señales](unidad14-buzzer/)
- [Unidad 15 — Servomotores](unidad15-servomotores/)
- [Unidad 16 — Motores DC y etapa de potencia](unidad16-motores-dc/)
- [Unidad 17 — Pantallas y visualización](unidad17-pantallas/)

### Nivel 6 — Comunicación e integración
- [Unidad 18 — Comunicación serial entre dispositivos](unidad18-comunicacion-serial/)
- [Unidad 19 — I2C y SPI: fundamentos](unidad19-i2c-spi/)
- [Unidad 20 — Diseño de prototipos y alimentación](unidad20-diseno-alimentacion/)

### Nivel 7 — Proyectos
- [Unidad 21 — Proyecto: sistema de monitoreo](unidad21-proyecto-monitoreo/)
- [Unidad 22 — Proyecto: sistema automatizado](unidad22-proyecto-automatizacion/)
- [Unidad 23 — Proyecto final libre](unidad23-proyecto-final/)

## Metodología

Cada práctica seguirá, cuando corresponda:

1. propósito;
2. componentes;
3. concepto electrónico;
4. diagrama/conexiones;
5. comprobaciones antes de energizar;
6. código;
7. explicación;
8. prueba;
9. errores frecuentes;
10. reto de modificación.

## Seguridad

Este curso trabaja con electrónica de **baja tensión**. No incluye conexión directa a la red eléctrica doméstica.

Nunca conectes motores, cargas de potencia o dispositivos de tensión/corriente desconocida directamente a un pin de Arduino.

## Principio del curso

> Primero comprende el circuito. Después energiza. Luego programa. Finalmente integra.

## Relación con Aprende con Leli

Arduino forma parte del área de **IoT y Robótica** de Aprende con Leli y se conecta con el curso de ESP32 e Internet de las Cosas.

## Estado

Curso completo con 24 unidades organizadas en siete niveles, prácticas, sketches, ejercicios, diagnóstico de hardware, plantillas de diseño y proyecto final con rúbrica técnica.

## Autora

**Leli Liliana Díaz Izquierdo**

Ingeniera de Sistemas · Docente investigadora · Tecnología, educación e investigación.

---

### ¿Necesitas acompañamiento personalizado?

Puedes estudiar este curso por tu cuenta. Si necesitas apoyo para configurar el entorno, comprender o resolver un error, o aplicar lo aprendido a tu tesis o proyecto, podemos trabajarlo en una sesión individual.

- **Preparar el entorno:** revisar la instalación y configuración de herramientas y dependencias.
- **Comprender y resolver errores:** analizar lo que ocurre y trabajar en una solución.
- **Aplicarlo a tu proyecto:** te acompaño a comprender el contenido y adaptarlo a tu caso.

[**Solicitar asesoría sobre este curso**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20revisando%20el%20curso%20de%20Arduino%20desde%20cero%20(lelyliliana%2FCurso-Arduino)%20y%20me%20interesa%20una%20asesor%C3%ADa%20personalizada.%20Necesito%20apoyo%20con%E2%80%A6)
