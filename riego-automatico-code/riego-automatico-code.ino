#include <EEPROM.h> // Librería para utilizar la memoria EEPROM
#define RELAY_PIN 4  // Pin al que está conectado el relé
#define INTERVALO_EN_SEGUNDOS 43200 // 12 horas en segundos

unsigned long tiempoAnterior = 0;
unsigned long tiempoGuardado = 0;
bool bombaEncendida = false;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Asegurarse de que la bomba esté apagada al inicio

  // Leer el tiempo guardado en la memoria EEPROM
  EEPROM.begin(sizeof(tiempoGuardado));
  EEPROM.get(0, tiempoGuardado);
  EEPROM.end();
}

void loop() {
  unsigned long tiempoActual = millis();

  if (!bombaEncendida) {
    // Si la bomba no está encendida, verifica si ha pasado el tiempo necesario
    if (tiempoActual - tiempoGuardado >= INTERVALO_EN_SEGUNDOS * 1000UL) {
      // Enciende la bomba
      digitalWrite(RELAY_PIN, HIGH);
      bombaEncendida = true;
      tiempoAnterior = tiempoActual;
    }
  } else {
    // Si la bomba está encendida, verifica si ha pasado un tiempo mínimo (por ejemplo, 5 segundos)
    if (tiempoActual - tiempoAnterior >= 5000UL) {
      // Apaga la bomba
      digitalWrite(RELAY_PIN, LOW);
      bombaEncendida = false;
      tiempoGuardado = tiempoActual; // Guarda el tiempo actual como la última vez que se encendió
      // Guarda el tiempo en la memoria EEPROM
      EEPROM.begin(sizeof(tiempoGuardado));
      EEPROM.put(0, tiempoGuardado);
      EEPROM.commit();
      EEPROM.end();
    }
  }
}
