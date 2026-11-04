#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "WLAN-352023";
const char* password = "lCEbWQTjV1Cneq";

WebServer server(80);


void startseite() {
  server.send(200, "text/html", "<h1>Hallo</h1>");
  

}
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Verbinde");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());
  server.on("/", startseite);
  server.begin();
}

void loop() {
  server.handleClient();

}
