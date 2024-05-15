#define PIN_SENSOR_PEATONES 2
#define PIN_SEMAFORO_PEATONES_VERDE 3
#define PIN_SEMAFORO_PEATONES_ROJO 4

void setup() {
  pinMode(PIN_SENSOR_PEATONES, INPUT);
  pinMode(PIN_SEMAFORO_PEATONES_VERDE, OUTPUT);
  pinMode(PIN_SEMAFORO_PEATONES_ROJO, OUTPUT);
}

void loop() {
  // Detección de peatones
  if (digitalRead(PIN_SENSOR_PEATONES) == HIGH) { 
    digitalWrite(PIN_SEMAFORO_PEATONES_VERDE, HIGH); 
    digitalWrite(PIN_SEMAFORO_PEATONES_ROJO, LOW);
    delay(10000); 
  } else {
    digitalWrite(PIN_SEMAFORO_PEATONES_VERDE, LOW); 
    digitalWrite(PIN_SEMAFORO_PEATONES_ROJO, HIGH); 
  }
}
