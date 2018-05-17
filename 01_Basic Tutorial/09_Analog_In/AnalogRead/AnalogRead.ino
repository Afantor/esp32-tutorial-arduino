#define RLED 14
#define InPin 33

int x ;

void setup() 
{
  Serial.begin(115200);
  pinMode(RLED, OUTPUT);
}

void loop()
{
  digitalWrite(RLED, LOW);
  delay(100);
  x = analogRead( InPin );
  Serial.println( x );
  digitalWrite(RLED, HIGH);
  delay(100);
}