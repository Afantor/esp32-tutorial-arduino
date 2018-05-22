#include <WiFi.h>
#include <FS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
const char* ssid = "yourNetworkName";
const char* password =  "yourNetworkPassword";
AsyncWebServer server(80);
void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.print("Server IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("\n\n");
  server.on("/printIp", HTTP_GET, [](AsyncWebServerRequest *request){ 
    request->send(200, "text/plain", "ok");
    Serial.print("Received request from client with IP: ");
    Serial.println(request->client()->remoteIP());
  });
  server.begin();
}
void loop(){}
