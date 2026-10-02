const int POT = A0;
const int LED = 9; // pin PWM en Arduino Uno

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int lectura = analogRead(POT);
  int brillo = map(lectura, 0, 1023, 0, 255);
  analogWrite(LED, brillo);
}
