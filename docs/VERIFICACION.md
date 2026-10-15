# Verificación de Arduino 1.2

## Comprobaciones reproducibles

Desde raíz, un comando por vez (python3 o py -3 según instalación):

```text
python scripts/verificar_material.py
```

```text
python scripts/probar_logica.py
```

```text
python scripts/compilar.py
```

El verificador controla catálogo, enlaces locales, nombres de carpetas Arduino y que headers copiados coincidan con las reglas probadas. Las pruebas nativas utilizan compilador C++ de escritorio (`g++` o `clang++`); no requieren placa, pero sí ese compilador.

## Ampliación didáctica 1.2 (2026-10-14, America/Bogota)

- Los 26 programas se recompilaron correctamente para `arduino:avr:uno` con Arduino CLI 1.2.2, AVR 1.8.6, Servo 1.3.0 y LiquidCrystal 1.0.7. Los sketches y headers no se modificaron en esta ampliación.
- Se ejecutaron de nuevo los 26 casos lógicos de escritorio; todos aprobados.
- Se comprobaron enlaces locales de todo el material, acceso a los 24 desarrollos desde unidades/laboratorios y estructura XML de los 20 esquemas SVG.
- Los 20 SVG se renderizaron y revisaron visualmente para detectar recortes y superposiciones. Se contrastaron sus etiquetas con los programas y tablas de conexiones. No representan una simulación eléctrica ni un montaje físico probado.
- Las tablas numéricas se contrastaron con las reglas: periodo completo, ADC/porcentaje, PWM, filtro, conversión TMP36, distancia e histéresis. Las predicciones temporales se identifican como nominales, no como mediciones físicas.

## Registro anterior (2026-10-13)

- **26 programas compilados correctamente** para `arduino:avr:uno`, core AVR 1.8.6, Servo 1.3.0 y LiquidCrystal 1.0.7, mediante Arduino CLI 1.5.1.
- **26 casos lógicos aprobados**: extremos ADC/PWM, conversión TMP36, valores inválidos, distancia/timeout, histéresis, pulsación estabilizada, desbordamiento de millis y validación de tramas.
- Catálogo y enlaces locales comprobados sin archivos faltantes; las copias de headers coinciden con las funciones probadas.

Los casos lógicos se ejecutaron con g++ de escritorio en C++11. Compilación y pruebas no cargaron firmware a una placa física ni simularon señales eléctricas.

## Pendiente de hardware

Cableado real, corriente, tensión, precisión de sensores, comunicación entre placas, LCD, servo y driver/motor. La compilación no confirma condiciones eléctricas ni resultados físicos. El estado observado se registra por práctica; nunca se marca una prueba no ejecutada como exitosa.
