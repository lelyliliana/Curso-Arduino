# Del tiempo de eco a una distancia válida

[Unidad](README.md) · [Laboratorio](LABORATORIO.md) · [Soluciones](SOLUCIONES.md)

**Programas de referencia:** [distancia_timeout](ejemplos/distancia_timeout/distancia_timeout.ino). Abre el archivo completo mientras sigues el desarrollo.


## Esquema de conexiones

Estos esquemas muestran terminales y recorridos eléctricos, no posiciones de una protoboard ni orientaciones universales de componentes. Contrasta las etiquetas con tu pieza y con [la tabla de conexiones](../docs/CONEXIONES.md).

![HC-SR04 con Uno R3 de lógica 5 V](../docs/esquemas/ultrasonido.svg)


## 1. Distingue salida e información recibida

TRIG en D7 es una salida que solicita el disparo. ECHO en D6 es una entrada cuya duración representa el recorrido de ida y vuelta. El módulo de referencia trabaja a 5 V con Uno R3; esa conexión no se transfiere directamente a una placa ESP32 de lógica 3.3 V.

En `setup` se prepara TRIG como OUTPUT y se deja LOW. `loop` espera aproximadamente 100 ms entre solicitudes. El pulso de disparo pasa de LOW a HIGH durante 10 microsegundos y vuelve a LOW. Milisegundos y microsegundos no son intercambiables: 1 ms equivale a 1000 µs.

## 2. Por qué dividir entre dos

El modelo usa 0.0343 centímetros por microsegundo, equivalente aproximado a 343 m/s. Si el eco dura 1000 µs, el sonido recorrió 34.3 cm en total. La distancia al objeto es la mitad: 17.15 cm.

| Duración del eco | Cálculo | Decisión de referencia |
|---:|---|---|
| 0 µs | No hay tiempo válido | Rechaza |
| 100 µs | 1.715 cm | Rechaza por rango |
| 1000 µs | 17.15 cm | Acepta |
| 25000 µs | 428.75 cm | Rechaza por rango |

`Curso::distanciaCm` convierte y exige 2..400 cm. El rango es un contrato de la práctica, no una garantía de precisión uniforme del módulo.

## 3. Esperar tiene un costo

`pulseIn(ECHO, HIGH, 25000UL)` espera un pulso con un timeout de 25000 µs. Puede bloquear el recorrido durante parte de ese tiempo. Usar `millis` para espaciar disparos no convierte toda operación del programa en no bloqueante.

Si retorna cero, el programa anuncia ausencia de lectura válida. Cero centímetros sería una afirmación física diferente. No conviertas un fallo de adquisición en un objeto pegado al sensor.

## 4. Ensayo con una referencia

Coloca una superficie plana frente al sensor y mide con regla la distancia desde una referencia física definida. Registra esperado, observado y diferencia en 10, 30 y 100 cm. Repite cada caso varias veces. Una sola lectura cercana no demuestra exactitud en todo el rango.

Después prueba una superficie inclinada o fuera del alcance del ensayo. Puede perderse el eco. Temperatura, geometría y materiales afectan el resultado; no corrijas esas diferencias con un número arbitrario sin investigar su causa.

## 5. Separar conversión y adquisición

La función de conversión puede probarse con tiempos inventados de forma controlada, como 1000 µs. Eso comprueba fórmula y rechazo, pero no el sensor. En una copia podrías imprimir una conversión de referencia desde `setup`; registra que el tiempo fue inyectado, no medido.

[Realizar el laboratorio](LABORATORIO.md) · [Contrastar las respuestas](SOLUCIONES.md) · [Volver a la unidad](README.md)
