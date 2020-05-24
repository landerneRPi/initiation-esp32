#include <Arduino.h>
#include <WiFi.h>

// nom de l’AP sur lequel on va se connecter
const char* ssid = "nom_AP";
// mot de passe de l’AP sur lequel on va se connecter
const char* password = "mot de passe";

// attente en millisecondes
#define DELAY 1000

// configuration initiale:
void setup() {
  // liaison série avec le PC (via USB) 
  Serial.begin(115200);
  // attendre un peu que la connexion se fasse
  delay(1000);
	Serial.println("\n");

  // connexion au point d'accès
  WiFi.begin(ssid, password);
	Serial.print("Connexion en cours...");
	// attente active de la connexion avec l'AP
	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(100);
	}
	
	Serial.println("\n");
	Serial.println("Connexion etablie!");
	Serial.print("Adresse IP de l'ESP32: ");
  // affichage sur le terminal de l'adresse IP acquise par l'ESP32 auprès de l'AP
	Serial.println(WiFi.localIP());

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
