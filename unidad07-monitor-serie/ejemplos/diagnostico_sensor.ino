const int SENSOR = A0;
unsigned long anterior = 0;
const unsigned long INTERVALO = 250;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long ahora = millis();

  if (ahora - anterior >= INTERVALO) {
    anterior = ahora;

    int lectura = analogRead(SENSOR);
    Serial.print("tiempo=");
    Serial.print(ahora);
    Serial.print(",lectura=");
    Serial.println(lectura);
  }
}
