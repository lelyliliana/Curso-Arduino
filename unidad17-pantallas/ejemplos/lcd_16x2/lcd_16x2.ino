#include <Arduino.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
unsigned long ultimo = 0;
void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print(F("Curso Arduino"));
}
void loop() {
  if (millis() - ultimo >= 500) {
    ultimo = millis();
    int raw = analogRead(A0);
    lcd.setCursor(0, 1);
    lcd.print(F("ADC="));
    lcd.print(raw);
    lcd.print(F("     "));
    Serial.println(raw);
  }
}
