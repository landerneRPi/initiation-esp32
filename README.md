# initiation-esp32
Initiation ESP32

Programmation en mode **Arduino** en utilisant **PlatformIO**.

## Configuration du projet PlatformIO

Dans **platformio.ini**, défintions:

* carte: nodemcu-32s
* plateforme: espressif32
* infrastructure de développement: arduino

## Configuration de la liaison série pour le moniteur

La liaison série est définie par défaut sur la connexion USB en utilisant **Serial**

* Serial.begin: initialisation de la connexion
* Serial.println: affichage sur le moniteur

## Faire clignoter une LED

Configuration de la LED: LED interne sur le GPIO 2:

* digitalWrite: pour définir l'état de la LED (niveau haut: allumé, niveau bas: éteint)

## Compilation

Menu Codium / Extension PlatformIO: tâche **Build**

## Téléchargement

Menu Codium / Extension PlatformIO: tâche **Upload**

## Affichage Moniteur

Configuration de la vitesse du moniteur, dans le fichier **platformio.ini**:

```
; vitesse du moniteur
monitor_speed = 115200
```

Menu Codium / Extension PlatformIO: tâche **Monitor**

ou deux en un: *Téléchargement et Moniteur*:

Menu Codium / Extension PlatformIO: tâche **Upload and Monitor**

## Fichier complet platformio.ini

```
[env:nodemcu-32s]
platform = espressif32
board = nodemcu-32s
framework = arduino
; vitesse du moniteur
monitor_speed = 115200
```
