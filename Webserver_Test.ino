#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "WLAN-352023";
const char* password = "lCEbWQTjV1Cneq";

WebServer server(80);

const char webseite[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1> random Text und so...</h1>
</body>
</html>
)rawliteral";

void startseite() {
  server.send(200, "text/html", webseite);
  

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
