# Laboratorio 20: Presupuesto de alimentación y límites de medición

**[Desarrollo paso a paso: Diseñar alimentación y reconocer una medición circular](DESARROLLO.md)**. Sigue el recorrido del código, las tablas y los experimentos antes de resolver la práctica.

[Unidad](README.md) · [Entorno](../docs/ENTORNO.md) · [Conexiones de referencia](../docs/CONEXIONES.md)


## Esquema de conexiones

Estos esquemas muestran terminales y recorridos eléctricos, no posiciones de una protoboard ni orientaciones universales de componentes. Contrasta las etiquetas con tu pieza y con [la tabla de conexiones](../docs/CONEXIONES.md).

![Divisor del propio riel: experimento ratiométrico](../docs/esquemas/divisor.svg)


## Objetivo y materiales

Presupuesto de alimentación y límites de medición. Utiliza la referencia **Uno R3 con ATmega328P**; Uno R4 y placas de 3.3 V no son sustitutos eléctricos automáticos.

Uno por USB. Divisor 10 kΩ+10 kΩ desde su propio 5 V a GND: unión→A1. Multímetro para medir 5 Vexternamente, si disponible. No conectar fuentes externas a este divisor.

Los números D/A corresponden a etiquetas de la tarjeta, no a patillas del chip. Trabaja con un montaje por vez, desenergiza antes de modificar cables y comprueba las conexiones en [CONEXIONES.md](../docs/CONEXIONES.md). Si tu componente tiene otra referencia, consulta su ficha y registra la adaptación.

## Preparación, paso a paso

1. Completa el entorno y diagnóstico USB de Unidad 00.
2. Monta sin alimentación los componentes indicados y revisa polaridad, referencia común y resistencia de cada LED.
3. Abre uno de los programas completos: [presupuesto_usb](ejemplos/presupuesto_usb/presupuesto_usb.ino). El archivo `.ino` y su carpeta tienen el mismo nombre; los `.h` adyacentes forman parte de ese programa.
4. Selecciona Uno y puerto, compila y lee los mensajes del IDE. Una compilación fallida no se corrige cambiando un cable.
5. Carga por USB y abre monitor a **115200 baud**. En prácticas de potencia conserva la fuente dedicada según el diseño de conexiones.
6. Ejecuta presupuesto_usb. Compara estimación con lectura del multímetro. Completa presupuesto de corriente de los componentes de tu proyecto.
7. Registra resultado antes de modificar una sola condición. Vuelve al programa original tras experimentar.

## Resultado esperado

Estimación queda cerca de 5 V porque referencia ADC es ese mismo riel: no permite verificar caída de fuente de forma independiente.

Este resultado es un criterio para comprobar, no una afirmación de prueba física ya realizada. Conserva fecha, placa, componentes, entrada, esperado y observado en [EVIDENCIAS.md](../docs/EVIDENCIAS.md). Identifica cuándo se trata de cálculo, simulación o hardware real.

## Lectura del programa

La medición ratiométrica depende de Ventrada/Vref. Si ambas cambian juntas, la cuenta conserva proporción. El experimento enseña por qué el software no demuestra que una fuente soporta carga. Dimensiona con fichas y medición independiente.

Lee primero `setup` para conocer el estado inicial, después `loop` y finalmente las funciones auxiliares. Si el ejemplo incluye `Logica.h` o `Trama.h`, abre ese archivo: contiene la regla real utilizada, no un paquete oculto. Las pruebas de escritorio utilizan las mismas funciones para verificar límites; todavía necesitas contrastar el montaje eléctrico.

## Ejercicios

1. ¿Por qué resultado cercano 5 V no certifica la fuente?
2. ¿Dónde incluir corriente de bloqueo?
3. ¿Qué debe mantenerse separado?

Intenta predecir antes de ejecutar y consulta [SOLUCIONES.md](SOLUCIONES.md) después. Explica la causa de una diferencia entre previsto y observado; no cambies el objetivo para convertir un fallo en éxito.

## Diagnóstico de la práctica

- Sin mensajes: comprueba cable de datos, puerto, velocidad y RESET antes de añadir periféricos.
- Programa cargado sin efecto: compara pin, polaridad y referencia de masa; desenergiza antes de corregir.
- Lecturas inesperadas: distingue ruido, entrada flotante, rango, sensor e interpretación; no conviertas un error en valor válido silenciosamente.
- Reinicios al añadir una carga: revisa presupuesto de fuente y etapa de potencia. El GPIO ordena, no alimenta motores.

## Alcance

No es un voltímetro de batería. No energices montajes de potencia sin diseño y protecciones apropiados.

Vuelve a [la unidad](README.md) para avanzar con su navegación. [Volver a Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/).
