

void setup() 
{
  Serial.begin(115200);
  int x = 10;
  Serial.print("x >> 1: ");
  Serial.println(x>>1);
  Serial.print("x >> 2: ");
  Serial.println(x>>2);
  Serial.print("x << 1: ");
  Serial.println(x<<1);
  Serial.print("x << 2: ");
  Serial.println(x<<2);
}
void loop() {
  
}
