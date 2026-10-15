# Del archivo al programa que ejecuta la placa

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [diagnostico_usb](ejemplos/diagnostico_usb/diagnostico_usb.ino). Abre el archivo completo mientras sigues el desarrollo.

## 1. Qué estamos intentando comprobar

La primera meta es establecer una conversación entre el computador y la placa. Todavía no conectes sensores: si el programa mínimo falla, un circuito adicional introduciría otra causa posible. Necesitas distinguir tres resultados: **compilar**, **cargar** y **observar**. Compilar transforma el código; cargar lo transfiere a la placa; observar permite contrastar que esa placa ejecuta lo esperado.

## 2. Sigue el primer recorrido

Abre el programa completo del laboratorio. `#include <Arduino.h>` incorpora declaraciones del entorno Arduino. Las llaves agrupan instrucciones y el punto y coma termina una instrucción. No tienes que escribir toda una aplicación de una vez: primero reconoce sus dos funciones principales.

`setup()` se ejecuta al comenzar, también después de RESET. `Serial.begin(115200)` establece la velocidad de comunicación. Los dos `println` siguientes envían un encabezado. `F("texto")` ayuda a conservar esos textos constantes en memoria de programa en la referencia AVR; no es una instrucción para imprimir más rápido.

`loop()` se repite. `static unsigned long ultimo = 0` conserva su valor entre llamadas; sin `static`, una variable local inicializada de nuevo no recordaría cuándo se envió el mensaje anterior. `millis()` entrega el tiempo transcurrido desde el arranque en milisegundos. La condición deja pasar aproximadamente un segundo antes de imprimir y actualizar la marca.

| Momento aproximado desde arranque | Qué hace la referencia |
|---|---|
| 0 ms | Configura Serial y envía el encabezado |
| 500 ms | La condición todavía no se cumple |
| 1000 ms | Actualiza `ultimo` e imprime el tiempo |
| 1500 ms | Espera sin detener el recorrido de `loop` |
| 2000 ms | Vuelve a imprimir |

Los números reales pueden superar ligeramente esas marcas. El programa no es un cronómetro calibrado.

## 3. Haz la primera observación

Compila primero. Si termina correctamente, carga y abre el monitor a 115200 baud. Puedes perder el encabezado por haber abierto el monitor tarde; pulsa RESET y observa otra vez. Tras reiniciar, el tiempo vuelve a un valor pequeño. Anota tres tiempos sucesivos y resta cada pareja: interesa el intervalo, no que aparezca exactamente 1000.

## 4. Cambia una sola decisión

Sustituye 1000 por 2000 en la condición. Antes de cargar, escribe cuántos mensajes esperas aproximadamente en diez segundos. Tras cargar observa el nuevo ritmo. Recupera la referencia al terminar. No cambies simultáneamente el puerto, la velocidad y el intervalo: sería difícil atribuir el resultado a una causa.

## 5. Explica un fallo

Si el monitor muestra caracteres ilegibles, comprueba primero la coincidencia de velocidades. Si no aparece el puerto, vuelve al cable de datos y a la identificación de la placa. Si el contador se reinicia repetidamente sin pulsar RESET, registra el reinicio como problema; no lo confundas con un intervalo corto de impresión.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las respuestas](SOLUCIONES.md) · [Volver a la unidad](README.md)
