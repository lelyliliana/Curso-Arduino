# Comprender un circuito antes de conectarlo

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [ley_ohm](ejemplos/ley_ohm/ley_ohm.ino). Abre el archivo completo mientras sigues el desarrollo.


## Esquema de conexiones

Estos esquemas muestran terminales y recorridos eléctricos, no posiciones de una protoboard ni orientaciones universales de componentes. Contrasta las etiquetas con tu pieza y con [la tabla de conexiones](../docs/CONEXIONES.md).

![Una salida con LED](../docs/esquemas/led.svg)


## 1. La corriente necesita un recorrido

Un LED necesita una diferencia de potencial, orientación correcta y limitación de corriente. En el esquema de esta unidad el recorrido es D8, resistencia, ánodo, cátodo y GND. No basta que todos los componentes estén presentes: sus terminales deben formar ese recorrido. Una fila de protoboard comparte contactos; el canal central normalmente separa grupos. Los rieles largos pueden estar interrumpidos. Compruébalos según tu protoboard.

## 2. Separa las tensiones

El modelo supone 5 V de fuente y 2 V de caída en un LED rojo. Por tanto la resistencia recibe aproximadamente `5 − 2 = 3 V`. Aplicar 5 V completos a la resistencia en el cálculo ignoraría la caída del LED.

| Resistencia | Cálculo de corriente | Resultado aproximado | Potencia en resistencia |
|---|---|---|---|
| 330 Ω | 3 / 330 A | 9.09 mA | 0.0275 W |
| 470 Ω | 3 / 470 A | 6.38 mA | 0.0191 W |
| 1000 Ω | 3 / 1000 A | 3.00 mA | 0.0090 W |

La conversión de amperios a miliamperios multiplica por 1000. La potencia se obtiene con `I × I × R`. En este modelo una resistencia de 1/4 W tiene margen frente a 0.0275 W. La elección real también considera tolerancias, tensión y ficha del componente.

## 3. Lee lo que el programa realmente hace

En `ley_ohm`, `fuente`, `caidaLed` y `resistencia` son constantes. El programa calcula usando esos números. No llama a `analogRead`, no mide un instrumento y no configura D8 como salida. Por eso el LED no tiene que encenderse al cargar este cálculo. La práctica física de salidas se realiza en la Unidad 03.

`float corriente` conserva una cantidad con decimales. `Serial.println(corriente * 1000, 2)` muestra dos decimales; eso controla la presentación, no aumenta la precisión del modelo. Del mismo modo, imprimir cuatro decimales de potencia no certifica una medición.

## 4. Construye por incrementos

Primero calcula con papel. Después carga el programa y compara. Cambia únicamente la resistencia del modelo a 470 y predice la corriente. Para el montaje físico, desconecta USB, identifica resistencia y polaridad, sigue el esquema y continúa en salidas digitales antes de energizar D8. No cambies la resistencia física esperando que el programa de constantes detecte el cambio.

## 5. Diferencia hipótesis y observación

Si el LED rojo se reemplaza por otro color, la caída de 2 V puede dejar de ser apropiada. El voltaje de una salida tampoco es una fuente ideal bajo cualquier carga. Si dispones de multímetro, medir tensión y medir corriente requieren conexiones diferentes. En corriente el instrumento se intercala en serie; nunca se conecta como un puente directo entre 5 V y GND.

**Práctica razonada:** explica por qué aumentar R reduce I en este modelo, pero no permite afirmar que el brillo percibido se reduce exactamente en esa proporción.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las respuestas](SOLUCIONES.md) · [Volver a la unidad](README.md)
