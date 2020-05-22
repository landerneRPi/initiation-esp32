#include <Arduino.h>

// attente en millisecondes
#define DELAY 1000

// configuration initiale:
void setup() {
  // liaison série avec le PC (via USB) 
  Serial.begin(115200);

  // pour l'ESP 32, LED_BUILTIN vaut 2 (GPIO 2)
  pinMode(LED_BUILTIN, OUTPUT);

  // message pour le moniteur
  Serial.println("Fin de configuration");
}

// boucle principale, infinie:
void loop() {
  // message pour le moniteur
  Serial.println("LED 2 allumée");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY);
  // message pour le moniteur
  Serial.println("LED 2 éteinte");
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY);
}
