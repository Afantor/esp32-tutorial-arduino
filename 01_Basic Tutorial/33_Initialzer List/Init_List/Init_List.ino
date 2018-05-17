

class TestClass{
  public:
    int x;
    int y:
    TestClass(int arg1, int arg2): x(arg1), y(arg2)
    {
    }
};

void setup()
{
  Serial.begin(115200);
  TestClass myObject(40, 30);
  Serial.print("Data member x:");
  Serial.println(myObject.x);
  Serial.print("Data member y:");
  Serial.println(myObject.y);
}

void loop()
{

  
}
