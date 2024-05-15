#include <Wire.h>
#include <BH1750.h>

#define PIN_RELE_ILUMINACION 3
#define PIN_SENSOR_LUZ_ADAFRUIT 4
#define PIN_SENSOR_LUZ_ADAFRUIT_VCC 5
#define PIN_SENSOR_LUZ_ADAFRUIT_GND 6

BH1750 sensorLuz;

void setup() {
  Serial.begin(9600);

  sensorLuz.begin();
  sensorLuz.setMTreg(32);

  pinMode(PIN_RELE_ILUMINACION, OUTPUT);
}

void loop() {
  float intensidadLuminosa = sensorLuz.readLightLevel();

  Serial.print("Intensidad Luminosa: ");
  Serial.println(intensidadLuminosa);

  if (intensidadLuminosa < 100) {
    digitalWrite(PIN_RELE_ILUMINACION, HIGH);
  } else {
    digitalWrite(PIN_RELE_ILUMINACION, LOW);
  }

  delay(1000);
}
