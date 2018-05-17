

class TestClass{
  public:
    int x = 1;
    int y = 2;
};


void setup() 
{
  Serial.begin(115200);
  TestClass myObject;
  Serial.print("Data member x value after creating object:");
  Serial.println(myObject.x);
  Serial.print("Data member y value after creating object:");
  Serial.println(myObject.y);
  myObject.x = 40;
  Serial.print("Data member x value after assignment:");
  Serial.println(myObject.x);
}


void loop() {
  
}
