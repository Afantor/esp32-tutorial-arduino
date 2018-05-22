#include <WiFi.h>
#include <WebSocketServer.h>
WiFiServer server(80);
WebSocketServer webSocketServer;
const char *ssid = "MyESP32AP";
const char *password = "testpassword";
void setup() {
  Serial.begin(115200);
  delay(4000);
  WiFi.softAP(ssid, password);
  Serial.println(WiFi.softAPIP());
  server.begin();
  delay(100);
}
void loop() {
  WiFiClient client = server.available();
  if (client.connected() && webSocketServer.handshake(client)) {
    String data;
    while (client.connected()) {
      data = webSocketServer.getData();
      if (data.length() > 0) {
         Serial.println(data);
         webSocketServer.sendData(data);
      }
      delay(10); // Delay needed for receiving the data correctly
   }
   Serial.println("The client disconnected");
   delay(100);
  }
  delay(100);
}
