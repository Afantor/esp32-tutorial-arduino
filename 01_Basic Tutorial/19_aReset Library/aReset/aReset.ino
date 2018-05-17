#include <WiFi.h>
#include <aREST.h>

aREST rest = aREST();

WiFiServer server(80);

const char* ssid = "yourNetworkName";
const char* password =  "yourNetworkPassword";


int testFunction(String command) 
{
  Serial.println("Received rest request");
}
void setup()
{
  Serial.begin(115200);
  rest.function("test",testFunction);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() 
{
  WiFiClient client = server.available();
  if (client) 
  {
    while(!client.available()){
      delay(5);
    }
    rest.handle(client);
  }
}

