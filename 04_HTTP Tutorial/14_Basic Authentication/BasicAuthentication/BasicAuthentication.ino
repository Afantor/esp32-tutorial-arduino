#include <WiFi.h>
#include <HTTPClient.h>
#include <base64.h>
const char* ssid = "yourNetworkName";
const char* password =  "yourNetworkPassword";
String authUsername = "testEsp32USer";
String authPassword = "testEsp32Pass";
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to WiFi");
}
void loop() {
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
    HTTPClient http;
    http.begin("http://192.168.1.88:8090/auth");
    String auth = base64::encode(authUsername + ":" + authPassword);
    http.addHeader("Authorization", "Basic " + auth);
    int httpCode = http.GET(); 
    if (httpCode > 0) { //Check for the returning code
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
    }
    else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  }
  delay(10000);
}
