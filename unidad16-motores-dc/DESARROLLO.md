# Separar control y potencia en un motor DC

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [motor_tb6612](ejemplos/motor_tb6612/motor_tb6612.ino). Abre el archivo completo mientras sigues el desarrollo.


## Esquema de conexiones

Estos esquemas muestran terminales y recorridos eléctricos, no posiciones de una protoboard ni orientaciones universales de componentes. Contrasta las etiquetas con tu pieza y con [la tabla de conexiones](../docs/CONEXIONES.md).

![Motor DC mediante carrier TB6612FNG](../docs/esquemas/motor.svg)


## 1. Sigue dos recorridos eléctricos

El Uno entrega órdenes a AIN1, AIN2, PWMA y STBY. La energía del motor llega al carrier TB6612FNG por VM desde una fuente de 6 V dimensionada para el motor de referencia. VCC alimenta la lógica del driver a 5 V. GND establece la referencia común. VM y VCC no son dos nombres intercambiables para la misma conexión.

El motor se conecta a AO1/AO2, no a un GPIO. El esquema usa nombres del carrier: comprueba su disposición real, desacoplo y condiciones de la ficha. Una fuente que soporta giro libre puede fallar durante arranque o bloqueo.

## 2. El estado de arranque tiene importancia

`setup` configura las salidas y llama a `parar`. Esta función lleva PWM a cero, las entradas de dirección a LOW y STBY a LOW. Además cambia `activo` a false. El pull-down de STBY mantiene deshabilitado el driver mientras el microcontrolador todavía no controla activamente ese pin.

## 3. Traza las órdenes

| Entrada | Condición previa | Decisión |
|---|---|---|
| f | Inactivo y rotor detenido por comprobación del operador | Dirección de referencia, PWM 128 |
| r | Inactivo y rotor detenido por comprobación del operador | Dirección contraria, PWM 128 |
| f o r | activo es true | Rechaza nueva marcha |
| 0 | Cualquier estado | Deshabilita salida |
| Tiempo activo >= 5000 ms | activo es true | Deshabilita salida |

El programa comprueba `activo`, pero no mide si el rotor está detenido. Tras enviar 0 todavía debes esperar la parada física antes de otra marcha. El nombre de una variable no crea un sensor.

## 4. Sigue la activación

Para f, IN1 es HIGH e IN2 LOW; para r ocurre lo contrario. Después habilita STBY, aplica PWM 128 y registra `inicio`. El sentido físico depende también de cómo estén conectados los terminales del motor. Cambiar los cables invierte la interpretación mecánica de adelante.

Mientras está activo, el límite de cinco segundos se revisa antes de atender nuevos caracteres. Si luego llega otra orden válida cuando ya está inactivo, puede iniciar otro intervalo. Ese timeout no impone reposo mecánico entre ciclos ni sustituye supervisión térmica.

## 5. Verificación por etapas

Primero contrasta pines y estados con el montaje desenergizado. Después realiza la prueba sin carga mecánica, con motor fijado y fuente adecuada. Envía f, observa, envía 0 y comprueba parada. Solo después prueba r. Registra corriente y condiciones únicamente si tienes instrumentación apropiada; PWM 128 no promete media velocidad ni media corriente.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las respuestas](SOLUCIONES.md) · [Volver a la unidad](README.md)
