#include <Arduino.h>
#include <WiFi.h>

// nom de l’AP sur lequel on va se connecter
const char* ssid = "monesp32";
// mot de passe de l’AP sur lequel on va se connecter
const char* password = "12345678";

// attente en millisecondes
#define DELAY 5000

// fonction d'affichage de la MAC adresse du client
void printMacAddress(system_event_ap_staconnected_t value) {
      Serial.print(" avec MAC adresse = ");
      Serial.print(value.mac[0],HEX);Serial.print(" ");
      Serial.print(value.mac[1],HEX);Serial.print(" ");
      Serial.print(value.mac[2],HEX);Serial.print(" ");
      Serial.print(value.mac[3],HEX);Serial.print(" ");
      Serial.print(value.mac[4],HEX);Serial.print(" ");
      Serial.print(value.mac[5],HEX);Serial.print(" ");
      Serial.print("\n");
}

// événements 'WiFi'
void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info)
{
  Serial.printf("[WiFi-event] event: %d\n", event);
  switch (event) {
    case SYSTEM_EVENT_WIFI_READY:
      Serial.println("WiFi Ready");
      break;
    case SYSTEM_EVENT_AP_START:
      Serial.println("WiFi access point started");
      break;
    case SYSTEM_EVENT_AP_STOP:
      Serial.println("WiFi access point  stopped");
      break;
    case SYSTEM_EVENT_AP_STACONNECTED:
      Serial.print("Client connected");
      printMacAddress(info.sta_connected);
      break;
    case SYSTEM_EVENT_AP_STADISCONNECTED:
      Serial.println("Client disconnected");
      break;
    case SYSTEM_EVENT_AP_STAIPASSIGNED:
      Serial.println("Assigned IP address to client");
      break;
    case SYSTEM_EVENT_AP_PROBEREQRECVED:
      Serial.println("Received probe request");
      break;   
    default: break;
  }
}

// configuration initiale:
void setup() {
  // liaison série avec le PC (via USB) 
  Serial.begin(115200);
  // attendre un peu que la connexion se fasse
  delay(1000);
	Serial.println("\n");

  // gestion des événements du WiFi
  WiFi.onEvent(WiFiEvent);
  // création du point d'accès
  Serial.println("Creation du point d'accès...");
	WiFi.softAP(ssid, password);

  // affichage sur le terminal/monitor de l'adresse IP du point d'accès de l'ESP32
	Serial.print("Adresse IP de l'AP: ");
	Serial.println(WiFi.softAPIP());
	Serial.println("\n");

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

  Serial.print("nombre de clients: ");
  Serial.print(WiFi.softAPgetStationNum());
  Serial.println();
}
