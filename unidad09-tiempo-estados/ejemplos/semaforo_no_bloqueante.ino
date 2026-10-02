const int ROJO = 8;
const int AMARILLO = 9;
const int VERDE = 10;

enum Estado { VERDE_ACTIVO, AMARILLO_ACTIVO, ROJO_ACTIVO };
Estado estado = VERDE_ACTIVO;

unsigned long cambioAnterior = 0;

void aplicarEstado() {
  digitalWrite(VERDE, estado == VERDE_ACTIVO);
  digitalWrite(AMARILLO, estado == AMARILLO_ACTIVO);
  digitalWrite(ROJO, estado == ROJO_ACTIVO);
}

void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  aplicarEstado();
}

void loop() {
  unsigned long ahora = millis();
  unsigned long duracion;

  switch (estado) {
    case VERDE_ACTIVO: duracion = 3000; break;
    case AMARILLO_ACTIVO: duracion = 1000; break;
    case ROJO_ACTIVO: duracion = 3000; break;
  }

  if (ahora - cambioAnterior >= duracion) {
    cambioAnterior = ahora;

    switch (estado) {
      case VERDE_ACTIVO: estado = AMARILLO_ACTIVO; break;
      case AMARILLO_ACTIVO: estado = ROJO_ACTIVO; break;
      case ROJO_ACTIVO: estado = VERDE_ACTIVO; break;
    }

    aplicarEstado();
  }

  // Otras tareas pueden ejecutarse aquí.
}
