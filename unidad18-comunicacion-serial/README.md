# Unidad 18 — Comunicación serial entre dispositivos

## Qué aprenderás
Diseñar un protocolo simple, recibir mensajes sin bloquear y validar datos antes de actuar.

# 1. Serial como enlace

Un enlace UART típico usa:
- TX;
- RX;
- referencia GND cuando corresponde;
- configuración compatible.

TX de un dispositivo se conecta normalmente al RX del otro según interfaz.

# 2. Niveles eléctricos

UART describe comunicación lógica, no garantiza tensión física universal.

Puede existir:
- TTL/CMOS a distintos niveles;
- RS-232 con niveles eléctricos diferentes;
- interfaces aisladas.

**No conectes RS-232 clásico directamente a GPIO TTL.**

Verifica niveles y usa transceptor/adaptación apropiada.

# 3. Baud y formato

Ambos extremos deben coincidir en parámetros relevantes:
- baud rate;
- bits de datos;
- paridad;
- stop bits,
según configuración.

Arduino Serial suele usar configuraciones comunes por defecto, pero comprende el contrato.

# 4. Bytes no son mensajes

La transmisión es un flujo.

Si envías:

```text
TEMP:25.4
LED:1
```

el receptor puede recibir bytes en fragmentos.

Necesitas saber dónde termina cada mensaje.

# 5. Delimitador

Una estrategia educativa:

```text
TEMP:25.4\n
```

Acumula hasta newline con límite de longitud.

Nunca permitas que un mensaje sin delimitador haga crecer un buffer indefinidamente.

# 6. Protocolo

Define:
- comandos;
- campos;
- separador;
- final de mensaje;
- rango;
- respuesta/error.

Ejemplo:

```text
SET_LED,1
SET_PWM,120
GET_TEMP
```

# 7. Validación

Antes de actuar:
1. comando conocido;
2. número parseable;
3. rango permitido;
4. cantidad de campos;
5. longitud máxima.

Un mensaje recibido no es confiable solo porque vino por cable.

# 8. Parsing no bloqueante

Evita esperar indefinidamente a que llegue un mensaje completo.

Lee bytes disponibles y mantén estado del parser.

Esto permite seguir atendiendo sensores/actuadores.

# 9. Respuestas

Define respuestas consistentes:

```text
OK
ERR,UNKNOWN_COMMAND
ERR,RANGE
```

Facilitan diagnóstico.

# 10. Serial USB vs hardware UART

Según placa, `Serial` puede estar ligado a USB/UART y compartir pines con programación/monitor.

Otras placas ofrecen Serial1/Serial2.

Consulta el core/pinout antes de conectar otro dispositivo.

# 11. Práctica guiada

Diseña parser para:
- LED ON/OFF;
- PWM 0–255;
- lectura sensor.

Prueba mensajes incompletos, largos y fuera de rango.

# 12. Errores frecuentes
- niveles incompatibles;
- RS-232 directo;
- asumir que read recibe mensaje entero;
- String/buffer sin límites;
- bloquear esperando newline;
- actuar sin validar.

# 13. Reto
Protocolo textual robusto con tres comandos, límites y respuestas de error.

# 14. Autoevaluación
1. ¿UART define voltaje universal?
2. ¿TX conecta con qué?
3. ¿Bytes = mensajes?
4. ¿Para qué delimitador?
5. ¿Qué validar?
6. ¿Serial puede compartir programación?

# 15. Checklist
- [ ] Niveles compatibles.
- [ ] Protocolo documentado.
- [ ] Buffer limitado.
- [ ] Parser no bloqueante.
- [ ] Entradas validadas.

Continúa con I²C y SPI.
