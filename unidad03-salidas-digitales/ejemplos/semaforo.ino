const int ROJO = 8;
const int AMARILLO = 9;
const int VERDE = 10;

void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void apagarTodos() {
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, LOW);
  digitalWrite(VERDE, LOW);
}

void loop() {
  apagarTodos();
  digitalWrite(VERDE, HIGH);
  delay(3000);

  apagarTodos();
  digitalWrite(AMARILLO, HIGH);
  delay(1000);

  apagarTodos();
  digitalWrite(ROJO, HIGH);
  delay(3000);
}
