const int POT = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(POT);
  int porcentaje = map(lectura, 0, 1023, 0, 100);

  Serial.print("ADC: ");
  Serial.print(lectura);
  Serial.print("  Porcentaje: ");
  Serial.print(porcentaje);
  Serial.println("%");

  delay(100);
}
