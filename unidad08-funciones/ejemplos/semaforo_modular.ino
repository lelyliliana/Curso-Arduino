const int ROJO = 8;
const int AMARILLO = 9;
const int VERDE = 10;

void configurarPines() {
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void mostrarEstado(bool rojo, bool amarillo, bool verde) {
  digitalWrite(ROJO, rojo);
  digitalWrite(AMARILLO, amarillo);
  digitalWrite(VERDE, verde);
}

void setup() {
  configurarPines();
}

void loop() {
  mostrarEstado(false, false, true);
  delay(3000);

  mostrarEstado(false, true, false);
  delay(1000);

  mostrarEstado(true, false, false);
  delay(3000);
}
