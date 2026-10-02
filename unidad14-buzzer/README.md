# Unidad 14 — Buzzer, tono y señales audibles

## Qué aprenderás
Distinguir buzzer activo/pasivo, generar patrones audibles sin bloquear y diseñar señales que comuniquen estados.

# 1. Identifica el componente

**Buzzer activo:** incorpora oscilador y suele producir un tono al energizarse dentro de su especificación.

**Buzzer pasivo/transductor:** necesita una señal alternante para producir una frecuencia audible.

No los distingas solo por apariencia. Revisa modelo/datasheet.

# 2. Antes de conectar

Verifica:
- tensión nominal;
- corriente;
- polaridad si aplica;
- si puede manejarse directamente desde GPIO según especificaciones;
- si requiere transistor/driver.

Un buzzer grande o sirena no debe asumirse como carga de GPIO.

# 3. tone

En placas/cores compatibles:

```cpp
tone(8, 1000, 200);
```

solicita aproximadamente 1000 Hz durante 200 ms.

La implementación usa recursos de temporización de la plataforma y puede interactuar con otras funciones/periféricos. Consulta documentación de tu placa si combinas temporizadores.

# 4. Frecuencia vs volumen

Cambiar frecuencia cambia principalmente el tono.

No asumas que una frecuencia mayor significa más volumen.

El nivel sonoro depende del transductor, alimentación, montaje y frecuencia de resonancia, entre otros factores.

# 5. noTone

```cpp
noTone(8);
```

detiene la generación en el pin según API.

# 6. Patrón no bloqueante

En vez de una cadena larga de tone+delay, modela:

```text
NORMAL
ADVERTENCIA
ALARMA
```

y usa millis para decidir cuándo cambia el tono/silencio.

Así botones/sensores siguen respondiendo.

# 7. Señal comprensible

No dependas solo del sonido para información crítica si el proyecto requiere accesibilidad/robustez.

Combina, cuando corresponda:
- luz;
- pantalla;
- sonido.

# 8. Frecuencias molestas

Evita exposición prolongada a señales intensas o muy molestas cerca del oído.

El objetivo es prototipar indicadores, no maximizar volumen.

# 9. Práctica guiada

Crea:
- confirmación corta;
- advertencia intermitente;
- alarma diferenciada.

Después intégralas a una máquina de estados sin delay principal.

# 10. Errores frecuentes
- activo/pasivo asumido;
- sirena grande en GPIO;
- frecuencia = volumen;
- secuencia bloqueante;
- sonido como única señal;
- ignorar conflictos de timers.

# 11. Reto
Sistema de tres estados con patrones inequívocos y temporización no bloqueante.

# 12. Autoevaluación
1. ¿Activo vs pasivo?
2. ¿Todo buzzer va directo a GPIO?
3. ¿Qué controla tone?
4. ¿Frecuencia = volumen?
5. ¿Por qué millis?
6. ¿Por qué señal multimodal?

# 13. Checklist
- [ ] Componente identificado.
- [ ] Carga segura.
- [ ] Patrón no bloqueante.
- [ ] Señales diferenciables.
- [ ] Recursos de timer considerados.

Continúa con servomotores.
