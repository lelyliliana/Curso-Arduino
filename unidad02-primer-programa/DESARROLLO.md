# Del primer encendido a una secuencia temporal

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [blink_medido](ejemplos/blink_medido/blink_medido.ino). Abre el archivo completo mientras sigues el desarrollo.

## 1. Reconoce las piezas del programa

Esta práctica usa el LED incorporado, por lo que todavía no necesitas montar una salida externa. `const byte LED = LED_BUILTIN` nombra el pin de la placa; en Uno R3 corresponde al LED de D13. `bool encendido` guarda solamente dos alternativas: verdadero o falso. La variable `ultimo` recuerda la última transición.

En `setup`, `pinMode(LED, OUTPUT)` prepara la salida y `digitalWrite(LED, LOW)` solicita el estado inicial apagado. Declarar una variable llamada LED no configura el pin; la configuración la realiza `pinMode`.

## 2. Sigue el tiempo sin saltarte el arranque

Cada vuelta de `loop` calcula el tiempo desde la transición anterior. Si todavía no han pasado 1000 ms, no cambia la salida. Cuando se cumple el intervalo, `encendido = !encendido` invierte el valor y `digitalWrite` lo aplica.

| Tiempo aproximado | Estado guardado | Salida solicitada | Mensaje |
|---|---|---|---|
| 0 ms | false | LOW | Ninguno periódico |
| 1000 ms | true | HIGH | ON |
| 2000 ms | false | LOW | OFF |
| 3000 ms | true | HIGH | ON |

Un ciclo completo puede medirse desde un ON hasta el ON siguiente: dura aproximadamente dos segundos. **El intervalo entre cambios es un segundo; el ciclo completo dura dos.**

## 3. Por qué una resta

El reloj vuelve a cero después de agotar su rango. La resta entre enteros sin signo permite comprobar intervalos cortos incluso al atravesar ese retorno, siempre que el programa compruebe con suficiente frecuencia. Es preferible a comparar con una suma que puede desbordar. No necesitas dominar todos los detalles del reloj todavía; sí reconocer que `ultimo` debe conservarse.

## 4. Modifica y predice

Cambia 1000 por 500. Ahora hay medio segundo en cada estado, de modo que ON más OFF dura un segundo. Para un ciclo completo de medio segundo con tiempos iguales, usa 250 por transición. No cambies el programa para hacer coincidir una predicción errónea: corrige primero qué entendías por periodo.

Después comenta únicamente la instrucción `digitalWrite`. Los mensajes seguirían alternando porque la variable cambia, aunque la salida ya no reciba cada actualización. Restaura esa instrucción. Este contraste muestra por qué un mensaje de software no demuestra por sí solo el comportamiento físico.

## 5. Comprueba con una observación útil

Cuenta varias transiciones, no solo una. Si cronometra una persona, el tiempo de reacción introduce error; medir diez ciclos y dividir reduce su efecto relativo. Describe el instrumento usado y evita presentar tiempos humanos como medidas exactas de la señal eléctrica.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las respuestas](SOLUCIONES.md) · [Volver a la unidad](README.md)
