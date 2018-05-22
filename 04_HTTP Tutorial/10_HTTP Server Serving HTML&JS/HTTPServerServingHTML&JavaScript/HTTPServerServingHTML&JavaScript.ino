#include <WiFi.h>
#include <FS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
const char* ssid = "yourNetworkName";
const char* password =  "yourNetworkPass;
AsyncWebServer server(80);
const char HTML[] PROGMEM = "<script language=\"JavaScript\">function formToJson(form){var pass=form.pass.value;var ssid=form.ssid.value;var jsonFormInfo=JSON.stringify({pass:pass, ssid: ssid});window.alert(jsonFormInfo);}</script> <form onSubmit=\"event.preventDefault(); formToJson(this);\"> <label class=\"label\">Network Name</label> <input type=\"text\" name=\"ssid\"/> <label>Password</label> <input type=\"text\" name=\"pass\"/> <input type=\"submit\" value=\"Submit\"></form>";
 
void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP());
  server.on("/html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", HTML);
  });
  server.begin();
}
 
void loop(){
}
