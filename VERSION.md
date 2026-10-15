# Versión 1.2: desarrollo didáctico y conexiones visuales

Fecha: 2026-10-14 (America/Bogota).

Las 24 unidades incorporan un desarrollo específico de sus programas, con progresión conceptual, tablas de seguimiento, interpretación de tipos y unidades, experimentos y diagnóstico. Se reescriben las 24 soluciones para explicar causas, fronteras y alcance, y se incorporan 20 esquemas SVG de conexiones funcionales enlazados desde 22 unidades. Las unidades 00 y 02 usan únicamente placa/USB.

El recorrido aclara especialmente periodo de transición frente a ciclo completo, código ADC frente a magnitud física, señal frente a potencia, evento frente a nivel, histéresis frente a filtrado y lectura plausible frente a sensor comprobado. Los proyectos describen sus políticas reales de error y silenciamiento.

Se conservan los 26 sketches y las reglas compartidas. Los ejemplos de modificación se realizan en copias; no se declara ampliado el hardware del integrador. Las comprobaciones y sus límites están en [VERIFICACION.md](docs/VERIFICACION.md).

---

# Versión 1.1: prácticas reproducibles

Fecha: 2026-10-13.

Se conserva el recorrido 00–23, se agregan 24 laboratorios y 24 soluciones razonadas, 26 programas de referencia y tablas de conexiones. El perfil es Uno R3/ATmega328P, Arduino AVR Boards 1.8.6, Servo 1.3.0 y LiquidCrystal 1.0.7.

## Implementaciones concretas

Identificación por ficha y diagnóstico USB; modelo LED/Ley de Ohm; salidas, pulsador estabilizado, ADC/PWM; comandos serial, funciones y temporización; reed/LDR; HC-SR04 con timeout; TMP36; piezo; servo con fuente propia; motor con TB6612FNG; LCD paralelo; enlace entre dos Uno con tramas; I2C y ensayo SPI loopback; presupuesto de potencia y experimento ratiométrico; bases de monitoreo, iluminación automática y alarma ambiental integrada.

Las reglas de conversión, histéresis, estabilización y tramas se prueban en escritorio mediante los mismos headers utilizados por los sketches. No sustituyen al hardware.

## Límites

La referencia no mide humedad ni conserva histórico. El ADC usa referencia aproximada; el divisor del propio 5 V no certifica tensión de fuente. Una lectura en rango no demuestra sensor conectado. Servo/motor no tienen realimentación de posición/velocidad. La comunicación Serial confirma recepción, no almacenamiento durable. Los proyectos utilizan LED y piezo como salidas de laboratorio; no son dispositivos de seguridad industrial ni controlan red doméstica.

Extensiones con pantallas, motores, CSV u otros sensores requieren montaje y pruebas documentados. Se conservan plantillas, rúbricas y retos; no se presentan como capacidades existentes del integrador.

Consulta docs/VERIFICACION.md y completa docs/EVIDENCIAS.md para separar compilación, prueba lógica y funcionamiento físico.
