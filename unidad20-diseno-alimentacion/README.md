# Unidad 20 — Diseño de prototipos y alimentación

## Qué aprenderás
Pasar de módulos aislados a un sistema con presupuesto eléctrico, distribución de potencia, estados seguros y plan de integración.

# 1. Antes de cablear

Produce:
1. diagrama de bloques;
2. lista de componentes;
3. tabla de pines;
4. tabla de tensiones y niveles;
5. presupuesto de corriente;
6. secuencia de funcionamiento;
7. estados de fallo;
8. plan de pruebas.

El prototipo empieza en papel.

# 2. Dominios

Separa conceptualmente lógica, sensores, comunicación, actuadores y potencia.

Pueden compartir una fuente física o no; la separación ayuda a analizar ruido y corriente.

# 3. Presupuesto de corriente

Para cada elemento registra:
- tensión;
- consumo típico;
- máximo relevante;
- pico de arranque o stall cuando aplique;
- fuente.

No sumes solo promedios. Considera picos simultáneos y margen.

# 4. Fuente

Debe cumplir:
- tensión adecuada;
- corriente suficiente;
- respuesta a transitorios;
- seguridad y protecciones;
- conector/cableado apropiado.

Una fuente capaz de entregar mucha corriente no fuerza automáticamente toda esa corriente por una carga sana; el circuito determina la demanda. Sin embargo, una falla puede disponer de mucha energía, por lo que protección importa.

# 5. Reguladores

En un regulador lineal, la diferencia de tensión multiplicada por corriente se convierte aproximadamente en calor.

Los convertidores switching suelen ser más eficientes, pero tienen consideraciones propias de ruido, layout y especificación.

Comprueba temperatura y potencia.

# 6. USB y pin 5 V

No trates USB o el regulador de la placa como fuente universal de motores y servos.

Revisa la ruta de alimentación de la placa concreta.

Conectar fuentes simultáneas incorrectamente puede producir backfeeding o conflictos.

# 7. Tierra común

Cuando circuitos no aislados intercambian señales, normalmente necesitan referencia común.

Con aislamiento óptico/digital u otras topologías puede haber dominios separados.

La pregunta correcta es:
> ¿cuál es el camino de retorno y referencia de esta señal?

# 8. Desacoplo

Condensadores cerca de IC y módulos ayudan con corrientes transitorias y ruido.

Valores y ubicación dependen del dispositivo y datasheet.

Un capacitor grande colocado al azar no sustituye un diseño correcto.

# 9. Motores

Considera:
- stall;
- driver;
- protección/recirculación;
- ruido;
- cableado;
- fuente;
- retorno de corriente.

Evita que corrientes de motor recorran caminos sensibles cuando sea posible.

# 10. Cables y conectores

La fuente y el driver pueden soportar la corriente mientras un jumper o protoboard no.

Dimensiona también:
- cable;
- pistas;
- conectores;
- terminales.

# 11. Estado seguro

Pregunta:
- ¿qué ocurre al encender?
- ¿durante reset?
- ¿si sensor se desconecta?
- ¿si comunicación falla?
- ¿si dato es inválido?
- ¿si alimentación cae?

Define salidas seguras.

# 12. Integración incremental

Orden posible:

```text
alimentación
→ lógica
→ un sensor
→ validar
→ pantalla
→ validar
→ actuador sin carga
→ validar
→ carga real
```

Integrar todo de una vez dificulta aislar fallos.

# 13. Medición

Comprueba según tus capacidades y seguridad:
- tensión de rails;
- corriente;
- temperatura;
- caídas al accionar cargas;
- resets;
- ruido en señales relevantes.

# 14. Documentación

Conserva:
- esquema;
- pinout;
- versión del código;
- datasheets;
- mediciones;
- decisiones.

Un prototipo reproducible vale más que uno que solo funciona una vez.

# 15. Práctica guiada

Diseña sensor + pantalla + actuador.

Haz presupuesto para:
- reposo;
- operación normal;
- peor caso razonable.

# 16. Errores frecuentes
- sumar solo típico;
- ignorar stall;
- USB para todo;
- GND común sin comprender aislamiento;
- capacitor mágico;
- protoboard para corriente alta;
- integrar todo de una vez;
- ignorar estado de reset.

# 17. Reto
Diseña completamente en papel un sistema y revísalo por energía, señales, fallos y secuencia de pruebas antes de conectarlo.

# 18. Autoevaluación
1. ¿Qué incluir en presupuesto?
2. ¿Una fuente fuerza toda su corriente?
3. ¿Qué disipa un regulador lineal?
4. ¿Cuándo referencia común?
5. ¿Qué es backfeeding?
6. ¿Por qué estado seguro?
7. ¿Por qué integrar por etapas?

# 19. Checklist
- [ ] Tensiones y niveles.
- [ ] Corrientes y picos.
- [ ] Drivers y reguladores.
- [ ] Retornos y señales.
- [ ] Cables y conectores.
- [ ] Estados seguros.
- [ ] Plan incremental.

Continúa con el proyecto de monitoreo.
