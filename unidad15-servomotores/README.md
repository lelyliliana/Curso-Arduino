# Unidad 15 — Servomotores: señal, posición y alimentación

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Controlar un servo RC separando señal y potencia, limitar recorrido mecánico y reconocer síntomas de alimentación insuficiente.

# 1. Qué es un servo RC

Integra normalmente:
- motor;
- engranajes;
- sensor de posición;
- controlador.

Recibe una señal de mando periódica cuya anchura de pulso representa una posición/orden según el servo.

No es simplemente “un motor que gira a grados exactos”.

# 2. Tres conexiones típicas

```text
alimentación
GND
señal
```

Los colores varían entre fabricantes. Verifica documentación.

# 3. Señal no es potencia

El pin Arduino proporciona la **señal de control**.

El servo obtiene la energía de su alimentación.

Un servo puede demandar picos importantes, especialmente:
- al arrancar;
- bajo carga;
- cerca del bloqueo mecánico.

# 4. Fuente externa

Para muchos montajes reales conviene una fuente adecuada al servo en vez de cargar el regulador/USB de la placa.

Si la señal no está aislada y ambos circuitos deben compartir referencia:

```text
GND fuente servo ↔ GND Arduino
```

Pero analiza arquitecturas con aislamiento por separado.

# 5. Biblioteca Servo

```cpp
#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
  servo.write(90);
}
```

La biblioteca genera la señal apropiada según core/placa.

# 6. 0–180 no es garantía mecánica

`servo.write(0)` y `180` representan comandos de la API, pero:
- el servo puede tener menos recorrido;
- el mecanismo montado puede limitarlo;
- los extremos pueden forzar engranajes.

Calibra límites seguros.

# 7. Señales de problema

- placa se reinicia;
- servo tiembla;
- USB se desconecta;
- movimiento errático;
- cables/regulador se calientan.

Pueden indicar alimentación, ruido, conexión o carga mecánica. No culpes primero al código.

# 8. Potenciómetro

```cpp
int adc = analogRead(A0);
int angulo = map(
  adc,
  0, 1023,
  MIN_ANGULO,
  MAX_ANGULO
);

servo.write(angulo);
```

Define límites por tu montaje.

# 9. Movimiento suave

No confundas “actualizar cada grado con delay” con control suave profesional.

Puedes programar objetivos y pasos temporizados con millis para no bloquear.

# 10. Torque

Un servo con torque insuficiente puede no alcanzar posición y consumir corriente elevada.

Selecciona por carga/lever arm/margen, no solo por tamaño físico.

# 11. Práctica guiada

1. prueba servo sin carga;
2. determina límites seguros;
3. controla con potenciómetro;
4. observa alimentación;
5. añade movimiento no bloqueante.

# 12. Errores frecuentes
- alimentar cualquier servo desde 5 V de placa;
- olvidar referencia común cuando aplica;
- forzar 0/180;
- confundir señal/potencia;
- ignorar corriente de bloqueo;
- usar delay largo para movimiento.

# 13. Reto
Control de posición con límites calibrados, fuente justificada y movimiento que no bloquee sensores.

# 14. Autoevaluación
1. ¿Señal alimenta servo?
2. ¿Cuándo GND común?
3. ¿0–180 es recorrido garantizado?
4. ¿Qué ocurre en bloqueo?
5. ¿Por qué puede reiniciarse Arduino?
6. ¿Torque importa?

# 15. Checklist
- [ ] Fuente dimensionada.
- [ ] Referencia correcta.
- [ ] Límites mecánicos.
- [ ] Sin bloqueo prolongado.
- [ ] Movimiento no bloqueante.

Continúa con motores DC.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 14 — Buzzer, tono y señales audibles](../unidad14-buzzer/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 16 — Motores DC, drivers y etapa de potencia](../unidad16-motores-dc/README.md)
