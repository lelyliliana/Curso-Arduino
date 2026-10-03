# Unidad 09 — millis(), tareas cooperativas y máquinas de estados

[Volver al índice del curso](../README.md) · [Ver el curso en Aprende con Leli](https://lelyliliana.github.io/aprende-con-leli/cursos/arduino/)

## Qué aprenderás
Gestionar varias tareas sin bloquear el loop y modelar comportamientos como estados/transiciones explícitas.

# 1. Problema de delay

```cpp
delay(5000);
```

Durante esa espera el sketch no avanza por loop para atender normalmente otras tareas.

Puede ser válido en ejemplos simples, pero limita sistemas interactivos.

# 2. millis

Devuelve un contador de milisegundos transcurridos desde el arranque, dentro del tipo utilizado por la plataforma Arduino correspondiente.

En Uno clásico se trabaja típicamente con `unsigned long`.

# 3. Patrón

```cpp
unsigned long anterior = 0;
const unsigned long INTERVALO = 500;

void loop() {
  unsigned long ahora = millis();

  if (ahora - anterior >= INTERVALO) {
    anterior = ahora;
    tarea();
  }

  otraTarea();
}
```

# 4. Por qué resta

No uses como patrón principal:

```cpp
if (ahora >= anterior + INTERVALO)
```

La resta con enteros unsigned está diseñada para seguir funcionando a través del wraparound natural del contador, siempre que los intervalos sean apropiados para el tipo.

# 5. Drift y planificación

```cpp
anterior = ahora;
```

programa el próximo intervalo respecto al momento real de ejecución.

```cpp
anterior += INTERVALO;
```

puede mantener mejor una cadencia ideal, pero requiere pensar qué hacer si la tarea se retrasó varias veces.

No existe una única opción universal.

# 6. Varias tareas

Cada tarea periódica puede tener su propio:
- último tiempo;
- intervalo;
- función.

```text
leer sensor cada 50 ms
actualizar pantalla cada 200 ms
registrar cada 1000 ms
```

# 7. Máquina de estados

```text
ESPERANDO
   ↓ botón
ACTIVO
   ↓ alarma
ALERTA
   ↓ reset
ESPERANDO
```

Un estado representa un modo del sistema.

Una transición expresa qué evento/condición permite cambiar.

# 8. enum

```cpp
enum Estado {
  ESPERANDO,
  ACTIVO,
  ALERTA
};

Estado estado = ESPERANDO;
```

Es más claro que números mágicos 0,1,2.

# 9. Estado vs evento

Estado:
> estoy en ALERTA.

Evento:
> el sensor acaba de superar el umbral.

No los confundas.

# 10. Acciones de entrada/salida

A veces una acción debe ocurrir una sola vez al entrar en un estado, no en cada iteración mientras permanezca allí.

Diseña transición/entrada explícitamente.

# 11. Recursos

Estudia [MAQUINA_ESTADOS.md](MAQUINA_ESTADOS.md) y [semaforo_no_bloqueante.ino](ejemplos/semaforo_no_bloqueante.ino).

# 12. Práctica guiada

Construye:
- LED cada 500 ms;
- lectura de botón continua;
- Serial cada 1 s.

Después añade tres estados.

# 13. Errores frecuentes
- reemplazar delay por otro bucle de espera;
- un solo temporizador para todo;
- comparar tiempos con suma sin comprender overflow;
- estados como números;
- ejecutar acción de entrada cada loop;
- confundir estado/evento.

# 14. Reto
Semáforo no bloqueante que responda a botón sin alterar la temporización principal.

# 15. Autoevaluación
1. ¿Qué bloquea delay?
2. ¿Por qué resta?
3. ¿anterior=ahora vs += intervalo?
4. ¿Qué es estado?
5. ¿Qué es transición?
6. ¿Por qué enum?

# 16. Checklist
- [ ] Loop sigue disponible.
- [ ] Temporizadores independientes.
- [ ] Patrón robusto a wraparound.
- [ ] Estados explícitos.
- [ ] Transiciones comprensibles.

Continúa con sensores digitales.


---

## Continuar el curso

- **Unidad anterior:** [Unidad 08 — Funciones y organización del código](../unidad08-funciones/README.md)
- **Volver al índice:** [Todas las unidades](../README.md)
- **Siguiente unidad:** [Unidad 10 — Sensores digitales](../unidad10-sensores-digitales/README.md)
