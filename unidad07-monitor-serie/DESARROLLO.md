# Construir un diálogo de comandos por Serial

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [monitor_comandos](ejemplos/monitor_comandos/monitor_comandos.ino). Abre el archivo completo mientras sigues el desarrollo.


## Esquema de conexiones

Estos esquemas muestran terminales y recorridos eléctricos, no posiciones de una protoboard ni orientaciones universales de componentes. Contrasta las etiquetas con tu pieza y con [la tabla de conexiones](../docs/CONEXIONES.md).

![Una salida con LED](../docs/esquemas/led.svg)


## 1. Un comando empieza como un carácter

El monitor envía bytes. El carácter `'1'` representa el símbolo escrito, no el valor numérico 1 recibido como una medición. En la referencia cada carácter se interpreta de manera independiente. Escribir `10` genera dos comandos: primero encender y después apagar.

`Serial.available()` informa si hay datos pendientes. Si no hay, `return` termina esa vuelta de `loop`; la siguiente vuelta podrá comprobar de nuevo. No detiene permanentemente el programa.

## 2. Sigue cada rama

| Carácter | Decisión | Cambio en salida |
|---|---|---|
| `'1'` | `digitalWrite(LED, true)` | Enciende |
| `'0'` | `digitalWrite(LED, false)` | Apaga |
| `'?'` | Consulta el nivel leído del pin | No modifica |
| CR o LF | Ignora fin de línea | No modifica |
| Otro | Informa comando inválido | No modifica |

En `c == '1' || c == '0'`, `||` significa que cualquiera de las dos comparaciones es suficiente. Después `c == '1'` da el valor que se escribe al pin. El código evita repetir dos bloques casi idénticos.

## 3. Por qué ignorar dos caracteres invisibles

El monitor puede añadir retorno de carro (CR, `\r`) y salto de línea (LF, `\n`). Si solo aceptaras `'1'` y `'0'`, un envío correcto podría generar errores extra por esos terminadores. La referencia los ignora expresamente. Ignorar terminadores no convierte el programa en un lector de números completos.

## 4. Prueba una conversación reproducible

Envía `1`, después `?`, después `x` y por último `?`. Espera ON, ON, mensaje inválido y ON. El carácter inválido conserva la salida. Después envía `10?`: las decisiones son ON, OFF y consulta OFF, aunque visualmente el primer encendido sea demasiado breve para reconocerlo.

La consulta usa `digitalRead` sobre un pin configurado como salida. Ese dato es una observación del nivel lógico del pin; no mide corriente del LED ni confirma que la rama esté conectada.

## 5. Añade ayuda con una responsabilidad concreta

En una copia añade una rama para `'h'` antes del rechazo de comandos inválidos. Su única responsabilidad es imprimir el uso. Comprueba que funciona estando ON y estando OFF y que no cambia ninguno de esos estados. Un comando informativo no debería modificar el dispositivo como efecto secundario.

Cuando necesites mensajes de varios caracteres, habrá que acumularlos, detectar su final y validarlos. La Unidad 18 desarrolla esa idea con un buffer limitado; no anticipes un parser completo simplemente convirtiendo cada carácter con una resta.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las respuestas](SOLUCIONES.md) · [Volver a la unidad](README.md)
