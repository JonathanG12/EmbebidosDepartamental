#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define PIN_BUS_ONE_WIRE 2
#define PIN_RELE 3

OneWire busOneWire(PIN_BUS_ONE_WIRE);
DallasTemperature sensores(&busOneWire);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  sensores.begin();
  pinMode(PIN_RELE, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Temp:");
}

void loop() {
  sensores.requestTemperatures();
  float temperatura = sensores.getTempCByIndex(0);
  lcd.setCursor(6, 0);
  lcd.print(temperatura);

  if (temperatura < 25) {
    digitalWrite(PIN_RELE, HIGH);
  } else {
    digitalWrite(PIN_RELE, LOW);
  }

  delay(1000);
}
