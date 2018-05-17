
class TestClass{
  public:
    int x;
    TestClass(int arg1)
    {
      x = arg1;
    }
};

int testFunction()
{
  return 10;
}


void setup() 
{
  Serial.begin(115200);
  auto myObject = TestClass(10);
  auto functionResult = testFunction();
  auto myInt = 20;
  Serial.print("Object data member: ");
  Serial.println(myObject.x);
  Serial.print("Function result: ");
  Serial.println(functionResult);
  Serial.print("Int variable: ");
  Serial.println(myInt);
}

void loop() {
  
}
