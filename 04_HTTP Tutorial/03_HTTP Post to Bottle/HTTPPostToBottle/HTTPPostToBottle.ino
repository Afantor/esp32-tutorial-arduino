#include <WiFi.h>
#include <HTTPClient.h>
const char* ssid = "yourNetworkName";
const char* password =  "yourNetworkPassword";

void setup() 
{
  Serial.begin(115200);
  delay(4000);   
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(500);
    Serial.println("Connecting..");
  }
  Serial.print("Connected to the WiFi network with IP: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   HTTPClient http;
   http.begin("http://192.168.1.88:8090/");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "text/plain"); //Specify content-type header
   int httpResponseCode = http.POST("Hello Bottle, from ESP32");//Send the actual POST request
   if(httpResponseCode>0){
    Serial.println(httpResponseCode);   //Print return code
   }else{
    Serial.print("Error on sending request: ");
    Serial.println(httpResponseCode);
   }
   http.end();  //Free resources
 }else{
    Serial.println("Error in WiFi connection");
 }
  delay(5000);  //Send a request every 5 seconds
}
