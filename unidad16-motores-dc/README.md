# Unidad 16 — Motores DC, drivers y etapa de potencia

**[Desarrollo paso a paso: Separar control y potencia en un motor DC](DESARROLLO.md)**. Sigue el recorrido del código, las tablas y los experimentos antes de resolver la práctica.

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Seleccionar una etapa de potencia a partir de tensión/corriente del motor y controlar dirección/velocidad sin exponer GPIO a la carga.

# 1. Regla

**Nunca conectes un motor DC directamente a un GPIO.**

Un motor:
- demanda mucha más corriente que una señal lógica;
- es inductivo;
- genera transitorios/ruido;
- tiene picos de arranque y bloqueo.

# 2. Arquitectura

```text
GPIO control ─→ driver/puente H ─→ motor
                     ↑
               fuente de potencia
```

Arduino decide. Driver conmuta potencia.

# 3. Datos del motor

Necesitas al menos:
- tensión nominal/rango;
- corriente sin carga si está disponible;
- corriente bajo carga;
- **stall current/corriente de bloqueo**;
- sentido/requisitos mecánicos.

La corriente de bloqueo suele ser mucho mayor que la de giro normal.

# 4. Dimensionar driver

El driver debe soportar:
- tensión del motor/fuente;
- corriente continua requerida;
- picos/arranque/bloqueo según escenario;
- disipación térmica;
- lógica compatible.

No selecciones un módulo solo porque “dice 2 A” en un anuncio: revisa datasheet, condiciones y disipación.

# 5. Caída de tensión

Drivers reales tienen pérdidas.

Un puente H puede entregar al motor menos tensión que la fuente, dependiendo de tecnología/corriente.

Drivers MOSFET modernos suelen tener pérdidas distintas de puentes bipolares antiguos.

# 6. Protección inductiva

Al interrumpir corriente en una carga inductiva aparecen transitorios.

Algunos drivers integran diodos/circuitería de recirculación; otros diseños requieren protección externa.

No añadas o elimines diodos sin revisar la topología/datasheet.

# 7. Dirección

Un puente H permite aplicar polaridad efectiva en ambos sentidos.

Nunca actives combinaciones prohibidas que produzcan conducción directa de la fuente (shoot-through) si el driver no lo impide.

Usa la tabla lógica del driver.

# 8. Velocidad

Si el driver lo permite, PWM puede modular la potencia efectiva.

```text
PWM GPIO → EN/PWM driver → motor
```

No significa que velocidad sea lineal con duty cycle: carga, fricción y motor influyen.

# 9. Fuente

La fuente debe cubrir corriente de motores con margen y dinámica apropiada.

No alimentes un motor desde el pin 5 V del Arduino por conveniencia.

# 10. GND común

Si control y potencia no están aislados y el driver espera niveles referidos a la lógica, conecta referencias según esquema del fabricante.

Con aislamiento, el diseño puede ser diferente.

# 11. Ruido

Motores pueden introducir:
- resets;
- lecturas ADC erráticas;
- ruido serial;
- EMI.

Mitigación puede incluir desacoplo, cableado, separación de potencia/lógica, protección y diseño físico.

No existe un único condensador mágico.

# 12. Prueba incremental

1. driver sin motor si el fabricante permite pruebas lógicas;
2. motor sin carga;
3. una dirección;
4. otra;
5. PWM;
6. carga real;
7. temperatura/corriente.

# 13. Práctica guiada

Elige un motor real y crea tabla:
- V;
- corriente nominal;
- stall;
- driver;
- fuente;
- margen.

Justifica con datasheets.

# 14. Errores frecuentes
- motor directo;
- driver por corriente típica solamente;
- ignorar stall;
- fuente insuficiente;
- módulo por título comercial;
- GND común como dogma incluso con aislamiento;
- velocidad = duty lineal.

# 15. Reto
Diseña dirección+velocidad para un motor concreto con presupuesto eléctrico y estrategia de fallo seguro.

# 16. Autoevaluación
1. ¿Por qué driver?
2. ¿Qué es stall current?
3. ¿Qué debe soportar driver?
4. ¿Fuente del pin 5 V?
5. ¿PWM = velocidad lineal?
6. ¿Qué causa resets?

# 17. Checklist
- [ ] Motor caracterizado.
- [ ] Driver con margen.
- [ ] Fuente adecuada.
- [ ] Protección revisada.
- [ ] Prueba incremental.

Continúa con pantallas.


---


## Laboratorio completo de referencia

Esta unidad incluye [montaje, programas y práctica paso a paso](LABORATORIO.md), [soluciones razonadas](SOLUCIONES.md) y [registro de evidencias](../docs/EVIDENCIAS.md).

**Práctica:** Motor DC con TB6612FNG.

**Alcance:** No conectar red doméstica. El ejemplo no implementa realimentación ni freno certificado.

## Continuar el curso

- **Unidad anterior:** [Unidad 15 — Servomotores: señal, posición y alimentación](../unidad15-servomotores/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 17 — Pantallas y visualización local](../unidad17-pantallas/README.md)

---

### ¿Necesitas apoyo con este tema?

Si te bloqueaste con la práctica, necesitas revisar tu entorno o adaptar lo aprendido a tu proyecto, podemos trabajarlo en una sesión personalizada.

[**Solicitar asesoría para este tema por WhatsApp**](https://wa.me/573103618296?text=Hola%2C%20Leli.%20Estoy%20estudiando%20Unidad%2016%20%E2%80%94%20Motores%20DC%20y%20etapa%20de%20potencia%20del%20curso%20Arduino%20desde%20cero%20%28https%3A%2F%2Fgithub.com%2Flelyliliana%2FCurso-Arduino%2Ftree%2Fmain%2Funidad16-motores-dc%29%20y%20necesito%20una%20asesor%C3%ADa%20personalizada.%20Mi%20duda%20es%E2%80%A6)
