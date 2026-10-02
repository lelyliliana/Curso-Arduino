const int BOTON = 2;
const int LED = 8;

bool ledEncendido = false;
bool estadoAnterior = HIGH;

void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  bool estadoActual = digitalRead(BOTON);

  if (estadoAnterior == HIGH && estadoActual == LOW) {
    ledEncendido = !ledEncendido;
    digitalWrite(LED, ledEncendido);
  }

  estadoAnterior = estadoActual;
  delay(20); // simplificación educativa de debounce
}
