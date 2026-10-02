# Unidad 21 — Proyecto: sistema de monitoreo

## Propósito
Construir un sistema que mida una magnitud real, determine la calidad de la lectura, presente información y genere estados sin bloquear.

No se evalúa solo que aparezca un número.

# Etapa 1 — Define qué medirás

Escribe:
- magnitud;
- rango esperado;
- unidad;
- frecuencia necesaria;
- qué decisión depende del dato.

Ejemplo:
> temperatura ambiental de un salón, 15–40 °C esperados, actualización cada 2 s.

# Etapa 2 — Caracteriza el sensor

Documenta:
- modelo exacto;
- datasheet/fuente;
- alimentación;
- interfaz;
- rango;
- precisión/tolerancia;
- resolución;
- intervalo mínimo;
- forma de reportar error.

No confundas resolución con exactitud.

# Etapa 3 — Diagrama

```text
entorno
  ↓
sensor
  ↓
lectura/validación
  ↓
estado
  ├── visualización
  └── alerta
```

# Etapa 4 — Prueba aislada

Antes de pantalla/alarma:
1. lee sensor;
2. registra Serial;
3. detecta inválidos;
4. compara con condiciones conocidas;
5. observa ruido/rango.

Conserva evidencia.

# Etapa 5 — Muestreo

Implementa lectura periódica con millis.

El intervalo debe respetar el sensor y la necesidad del sistema.

No leas a máxima velocidad porque puedas hacerlo.

# Etapa 6 — Validación

Distingue:

```text
lectura válida
lectura inválida
lectura fuera de rango plausible
sensor sin respuesta
```

No conviertas un error a cero si cero es un valor posible.

# Etapa 7 — Estado

Ejemplo:

```text
NORMAL
ADVERTENCIA
ALARMA
SENSOR_ERROR
```

Define umbrales e histéresis si el ruido puede provocar oscilación.

# Etapa 8 — Visualización

Usa Serial o pantalla.

Muestra:
- valor;
- unidad;
- estado;
- indicación clara de error.

No mantengas silenciosamente un valor antiguo como actual.

# Etapa 9 — Indicador

LED/buzzer según diseño.

La alerta no debe bloquear la adquisición.

# Etapa 10 — Alimentación

Haz tabla:
- componente;
- tensión;
- consumo relevante;
- fuente.

Para un proyecto solo de sensores puede ser simple, pero debe existir la justificación.

# Etapa 11 — Pruebas

Incluye:
- mínimo esperado;
- normal;
- umbral;
- cerca del umbral;
- máximo esperado;
- sensor desconectado;
- lectura inválida.

# Etapa 12 — Evidencia

README del proyecto:
1. objetivo;
2. diagrama;
3. BOM;
4. conexiones;
5. especificaciones;
6. código;
7. datos de prueba;
8. fallos/correcciones;
9. limitaciones.

# Reto de ampliación

Transmite los datos al computador u otro dispositivo mediante un protocolo documentado.

# Autoevaluación

1. ¿Mi número tiene unidad?
2. ¿Sé qué precisión tiene el sensor?
3. ¿Manejo lectura inválida?
4. ¿Muestreo sin bloquear?
5. ¿La alerta oscila cerca del umbral?
6. ¿Otra persona puede reproducirlo?

# Checklist

- [ ] Sensor caracterizado.
- [ ] Muestreo justificado.
- [ ] Validación.
- [ ] Estados.
- [ ] Visualización.
- [ ] Pruebas.
- [ ] Documentación.

Continúa con automatización.
