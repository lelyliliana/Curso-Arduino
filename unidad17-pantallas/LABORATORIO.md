# Laboratorio 17: LCD HD44780 de 16×2 en paralelo

**[Desarrollo paso a paso: Mostrar un dato sin perder la conexión de la pantalla](DESARROLLO.md)**. Sigue el recorrido del código, las tablas y los experimentos antes de resolver la práctica.

[Unidad](README.md) · [Entorno](../docs/ENTORNO.md) · [Conexiones de referencia](../docs/CONEXIONES.md)


## Esquema de conexiones

Estos esquemas muestran terminales y recorridos eléctricos, no posiciones de una protoboard ni orientaciones universales de componentes. Contrasta las etiquetas con tu pieza y con [la tabla de conexiones](../docs/CONEXIONES.md).

![LCD paralelo 16×2: seis señales de control](../docs/esquemas/lcd.svg)


## Objetivo y materiales

LCD HD44780 de 16×2 en paralelo. Utiliza la referencia **Uno R3 con ATmega328P**; Uno R4 y placas de 3.3 V no son sustitutos eléctricos automáticos.

LCD compatible 5 V de 16 pines, potenciómetro contraste 10 kΩ. Tabla detallada de abajo. Potenciómetro de entrada aparte a A0.

Los números D/A corresponden a etiquetas de la tarjeta, no a patillas del chip. Trabaja con un montaje por vez, desenergiza antes de modificar cables y comprueba las conexiones en [CONEXIONES.md](../docs/CONEXIONES.md). Si tu componente tiene otra referencia, consulta su ficha y registra la adaptación.

## Preparación, paso a paso

1. Completa el entorno y diagnóstico USB de Unidad 00.
2. Monta sin alimentación los componentes indicados y revisa polaridad, referencia común y resistencia de cada LED.
3. Abre uno de los programas completos: [lcd_16x2](ejemplos/lcd_16x2/lcd_16x2.ino). El archivo `.ino` y su carpeta tienen el mismo nombre; los `.h` adyacentes forman parte de ese programa.
4. Selecciona Uno y puerto, compila y lee los mensajes del IDE. Una compilación fallida no se corrige cambiando un cable.
5. Carga por USB y abre monitor a **115200 baud**. En prácticas de potencia conserva la fuente dedicada según el diseño de conexiones.
6. Carga lcd_16x2. Ajusta contraste. Gira pot de A0 y compara LCD con Serial.
7. Registra resultado antes de modificar una sola condición. Vuelve al programa original tras experimentar.

## Resultado esperado

Fila 1 muestra Curso Arduino; fila 2 muestra ADC actualizado sin dígitos residuales.

Este resultado es un criterio para comprobar, no una afirmación de prueba física ya realizada. Conserva fecha, placa, componentes, entrada, esperado y observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Identifica cuándo se trata de cálculo, simulación o hardware real.

## Lectura del programa

LiquidCrystal lcd(12,11,5,4,3,2) identifica RS, E, D4, D5, D6, D7. El modo 4 bits usa cuatro líneas de datos. No se llama clear cada loop: se sobrescribe región y espacios para evitar parpadeo.

Lee primero `setup` para conocer el estado inicial, después `loop` y finalmente las funciones auxiliares. Si el ejemplo incluye `Logica.h` o `Trama.h`, abre ese archivo: contiene la regla real utilizada, no un paquete oculto. Las pruebas de escritorio utilizan las mismas funciones para verificar límites; todavía necesitas contrastar el montaje eléctrico.

## Ejercicios

1. ¿Este código sirve sin cambios para backpack I2C?
2. ¿Por qué añadir espacios tras ADC?
3. ¿Qué revisar si hay luz pero no texto?

Intenta predecir antes de ejecutar y consulta [SOLUCIONES.md](SOLUCIONES.md) después. Explica la causa de una diferencia entre previsto y observado; no cambies el objetivo para convertir un fallo en éxito.

## Diagnóstico de la práctica

- Sin mensajes: comprueba cable de datos, puerto, velocidad y RESET antes de añadir periféricos.
- Programa cargado sin efecto: compara pin, polaridad y referencia de masa; desenergiza antes de corregir.
- Lecturas inesperadas: distingue ruido, entrada flotante, rango, sensor e interpretación; no conviertas un error en valor válido silenciosamente.
- Reinicios al añadir una carga: revisa presupuesto de fuente y etapa de potencia. El GPIO ordena, no alimenta motores.

## Alcance

La retroiluminación necesita corriente limitada según tu módulo; no asumir resistencia incorporada.

Vuelve a [la unidad](README.md) para avanzar con su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/).
