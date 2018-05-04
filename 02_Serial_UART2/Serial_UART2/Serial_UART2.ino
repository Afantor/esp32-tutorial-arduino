/*
  Serial for UART2
- 使用"HardwareSerial"类进行串行通信。它有一些重要的接口：
- HardwareSerial(int uart_nr)：这是HardwareSerial的构造函数，其中uart_nr为0,1或2，所以我们有最多3个串行端口。

- void begin(unsigned long baud，uint32_t config = SERIAL_8N1，int8_t rxPin = -1，int8_t txPin = -1)：用初始化串口:波特率,串口模式（默认为SERIAL_8N1）,rxPin和txPin（如果您保留这些参数为空库将使用默认引脚）。
- available()：获取从串口读取可用的字节数（字符）。
- print()：将可读的数据使用ASCII打印到串行端口。
- println()：将数据使用ASCII打印到串行端口，后跟回车符（ASCII 13或'\ r'）和换行符（ASCII 10或'\ n'）。
- read()：读取Rx引脚上输入的串行数据。
- readStringUntil()：将串行缓冲区中的字符读入字符串，直到遇到终止符。
- 因为Arduino库创建了一个默认实例HardwareSerial Serial(0)，因此您可以直接使用创建的Serial对象，而无需自己创建实例。
- 为了使用更多的串行端口，您只需创建另一个HardwareSerial实例，例如：HardwareSerial Serial1(1)或HardwareSerial Serial2(2)，然后常用方法使用它们。

  This example code is in the public domain.

  http://www.afantor.cc
*/

HardwareSerial Serial2(2);

int8_t U2rxPin = 16;
int8_t U2txPin = 17;

char inByte = 0;         // incoming serial byte
// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 115200 bits per second:
  Serial2.begin(115200,SERIAL_8N1,U2rxPin,U2txPin);
  while (!Serial2) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // serial print hello world.
  Serial2.println("Hello world!");
}

// the loop routine runs over and over again forever:
void loop() 
{
  // print out the value if Serial available.
  if (Serial2.available() > 0) 
  {
    // get incoming byte:
    inByte = Serial2.read();
    // send back values:
    Serial2.write(inByte);
  }
}
