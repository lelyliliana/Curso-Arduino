# Convertir una posición en una lectura ADC

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [potenciometro_adc](ejemplos/potenciometro_adc/potenciometro_adc.ino). Abre el archivo completo mientras sigues el desarrollo.


## Esquema de conexiones

Estos esquemas muestran terminales y recorridos eléctricos, no posiciones de una protoboard ni orientaciones universales de componentes. Contrasta las etiquetas con tu pieza y con [la tabla de conexiones](../docs/CONEXIONES.md).

![Potenciómetro como divisor](../docs/esquemas/potenciometro.svg)


## 1. Qué entrega el potenciómetro

Un potenciómetro tiene dos extremos y un cursor. Los extremos se conectan a 5 V y GND; el cursor a A0. Al girarlo cambia la proporción entre dos resistencias. En esta práctica la entrada ADC consume poca corriente respecto al divisor y observa la tensión del cursor.

Intercambiar los extremos invierte el sentido de giro asociado a valores altos. No cambia por sí mismo el rango del convertidor. No deduzcas la identidad del cursor solo por la apariencia de un componente distinto: compruébala con su ficha.

## 2. Qué número devuelve analogRead

El ADC de esta referencia tiene 10 bits: `2^10 = 1024` códigos. Están numerados desde 0 hasta 1023. No hay código 1024. Una cuenta representa aproximadamente `5 / 1024 ≈ 4.88 mV` si la referencia efectiva fuera exactamente 5 V.

El programa expresa la posición como `raw * 100L / 1023`. Aquí 1023 se usa para llevar los dos extremos de la escala a 0 y 100. Esa normalización de extremos tiene un propósito distinto del tamaño de paso del ADC, que usa 1024 niveles.

## 3. Sigue la aritmética sin perder tipos

El sufijo `L` hace que el producto se calcule como entero largo. En Uno AVR un `int` de 16 bits no alcanza para `1023 × 100 = 102300`. Sin cuidar el tipo, un cálculo aparentemente pequeño puede desbordar antes de dividir.

| raw | Producto con 100L | División entera por 1023 |
|---:|---:|---:|
| 0 | 0 | 0 |
| 256 | 25600 | 25 |
| 512 | 51200 | 50 |
| 768 | 76800 | 75 |
| 1023 | 102300 | 100 |

La división entera descarta la parte fraccionaria. No es redondeo al entero más cercano.

## 4. Una sola lectura, dos representaciones

Cada 200 ms se lee A0 una vez y se conserva en `raw`. Después se imprimen esa lectura y su porcentaje. Leer A0 otra vez para el porcentaje podría usar un instante distinto. Guardar una muestra permite explicar de dónde salieron ambos números.

Primero observa los extremos, después una posición intermedia. Cerca de una frontera pueden alternarse cuentas vecinas; no significa que el control físico esté recorriendo grandes distancias. Una entrada desconectada también puede mostrar números: la presencia de un número no demuestra una medición válida.

## 5. Extiende sin inventar unidades

Si quieres mostrar un decimal de porcentaje, cambia la expresión a `raw * 100.0f / 1023.0f` y usa una cifra decimal en `println`. El decimal evita truncamiento temprano, pero no calibra el sensor. Tampoco permite llamar al resultado grados, centímetros o resistencia sin un modelo adicional.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las respuestas](SOLUCIONES.md) · [Volver a la unidad](README.md)
