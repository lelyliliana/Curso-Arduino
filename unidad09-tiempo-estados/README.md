# Unidad 09 — Tiempo con millis() y máquinas de estados

## Objetivo
Gestionar tiempo sin detener todo el programa.

## Problema de delay()
Mientras delay() espera, el programa no puede reaccionar normalmente a otras tareas.

## millis()
Devuelve el tiempo aproximado transcurrido desde el inicio en milisegundos.

```cpp
const int LED = LED_BUILTIN;
unsigned long anterior = 0;
const unsigned long INTERVALO = 500;
bool estado = false;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  unsigned long ahora = millis();

  if (ahora - anterior >= INTERVALO) {
    anterior = ahora;
    estado = !estado;
    digitalWrite(LED, estado);
  }

  // Aquí pueden ejecutarse otras tareas.
}
```

Usar la resta `ahora - anterior` ayuda a trabajar correctamente con el desbordamiento natural del contador.

## Máquina de estados
Modela modos explícitos:
```text
ESPERANDO → ACTIVO → ALERTA
```

Cada estado define comportamiento y condiciones de transición.

## Reto
Construye un semáforo no bloqueante con millis() y estados.

## Qué sigue
Unidad 10 — Sensores digitales.
