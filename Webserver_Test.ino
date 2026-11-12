// ---------- Bibliotheken einbinden ----------
#include <WiFi.h>        // WLAN-Funktionen des ESP32 (verbinden, Status, IP)
#include <WebServer.h>   // Webserver-Funktionen (on, send, handleClient)

// ---------- WLAN-Zugangsdaten ----------
const char* ssid = "DEIN_WLAN_NAME";       // Name des WLANs (2,4 GHz)
const char* password = "DEIN_PASSWORT";    // WLAN-Passwort (Platzhalter!)

// ---------- Server-Objekt ----------
WebServer server(80);   // Server auf Port 80 (Standardport fuer Webseiten)

// ---------- Handler-Funktion fuer die Startseite ----------
// Wird ausgefuehrt, wenn der Browser die Adresse "/" aufruft
void startseite() {
  // Antwort an den Browser: Statuscode 200 (ok),
  // Inhaltstyp HTML, und der Inhalt selbst (eine Ueberschrift)
  server.send(200, "text/html", "<h1>Hallo</h1>");
}

// ---------- setup(): laeuft einmal beim Start ----------
void setup() {
  Serial.begin(115200);    // Serielle Verbindung zum PC starten (Baudrate 115200)

  WiFi.mode(WIFI_STA);     // ESP32 als Station: er wählt sich in ein vorhandenes WLAN ein
  WiFi.begin(ssid, password);  // Verbindungsaufbau starten (wartet nicht bis fertig)

  Serial.print("Verbinde"); // Text ausgeben, ohne Zeilenumbruch

  // Schleife: so lange wiederholen, bis die Verbindung steht
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);             // 500 ms warten
    Serial.print(".");      // Pro Durchlauf einen Punkt ausgeben
  }

  Serial.println();         // Zeilenumbruch
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());  // Die IP, die der Router vergeben hat (im Browser eingeben)

  server.on("/", startseite);  // Regel: Adresse "/" -> Funktion startseite
  server.begin();              // Server starten, ab jetzt werden Anfragen angenommen
}

// ---------- loop(): laeuft endlos ----------
void loop() {
  server.handleClient();   // Prueft, ob der Browser etwas angefragt hat,
                           // und fuehrt dann die passende Funktion aus
}
