# Arquitectura — Motor DC

## Nunca
```text
GPIO → motor
```

## Arquitectura correcta conceptual
```text
             señal de control
Arduino ─────────────────────→ driver
                                │
fuente de motor ────────────────┤
                                ↓
                              motor
```

Según el driver/circuito, las tierras pueden requerir referencia común. Consulta el módulo utilizado.

## Selección del driver
Debes conocer como mínimo:
- tensión del motor;
- corriente nominal;
- corriente de arranque/bloqueo cuando esté disponible;
- tensión/corriente soportada por el driver.

## Dirección
Un puente H permite invertir polaridad sobre el motor mediante señales de control.

## Velocidad
Puede controlarse mediante PWM si el driver y montaje lo permiten.

## Diagnóstico
### Arduino se reinicia
Posible caída de alimentación/interferencia.

### Motor no arranca
Comprueba fuente, driver, habilitación, conexiones y corriente disponible.

### Driver se calienta
Desconecta y revisa dimensionamiento.

## Reto
Selecciona un motor y un driver reales a partir de sus hojas de datos y justifica compatibilidad.
