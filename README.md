# Intelligentes Lüftungssystem – Smart Home durch automatische Fenstersteuerung

- Programiersprache: C++

- Links ESP32-S in Arduino Ide einstellen
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
https://github.com/arduino-libraries/Arduino_ESP32_OTA

- Servo Bibliothek
https://madhephaestus.github.io/ESP32Servo/annotated.html

- In unserem Projekt entwickeln wir ein intelligentes Lüftungssystem als Teil eines Smart-Home-Modells. Ziel ist es, die Raumluftqualität zu verbessern und gleichzeitig den Wärmeverlust beim Lüften möglichst gering zu halten. Dafür bauen wir ein Modell mit mehreren Räumen und motorbetriebenen Fenstern. Sensoren messen die CO₂-Konzentration, Temperatur und Luftfeuchtigkeit. Ein ESP32 verarbeitet diese Daten und steuert die Fenster automatisch, indem er sie je nach Bedarf unterschiedlich weit öffnet. Dabei berücksichtigt das System auch die gewünschte Raumtemperatur, um unnötiges Lüften und Wärmeverluste zu vermeiden. Über eine selbst entwickelte Website können Benutzer die Messwerte überwachen, Zieltemperaturen einstellen und einzelne Fenster auch manuell aus anderen Räumen heraus steuern. Durch verschiedene Versuche untersuchen wir, wie effektiv unser System die Luftqualität verbessern und gleichzeitig Wärmeverluste reduzieren kann.
