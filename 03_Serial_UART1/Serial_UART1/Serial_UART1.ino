/*
  Serial for UART1
我们使用“ HardwareSerial ”类进行串行通信。它有一些重要的接口：
- HardwareSerial（int uart_nr）：这是HardwareSerial的构造函数，其中uart_nr为0,1或2，所以我们有最多3个串行端口。

- void begin（unsigned long baud，uint32_t config = SERIAL_8N1，int8_t rxPin = -1，int8_t txPin = -1）：用波特率初始化串口，串口模式（默认为SERIAL_8N1），rxPin和txPin（如果您保留这些参数为空库将使用默认引脚）。
- available（）：获取可用于从串口读取的字节数（字符）。
- print（）：将数据作为可读的ASCII文本打印到串行端口。
- println（）：将数据打印到串行端口，作为人可读的ASCII文本，后跟回车符（ASCII 13或'\ r'）和换行符（ASCII 10或'\ n'）。
- read（）：读取Rx引脚上的输入串行数据。
- readStringUntil（）：将串行缓冲区中的字符读入字符串，直到遇到终止符。
- 因为Arduino库创建了一个默认实例HardwareSerial Serial（0），因此您可以直接使用创建的Serial对象（在下面的示例中），而无需自己创建实例。
- 为了使用更多的串行端口，您只需创建另一个HardwareSerial实例，例如：HardwareSerial Serial1（1）或HardwareSerial Serial2（2），然后照常使用它们。
  This example code is in the public domain.

  http://
*/

HardwareSerial Serial1(1);

int8_t U1rxPin = 16;
int8_t U1txPin = 17;

char inByte = 0;         // incoming serial byte
// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 115200 bits per second:
  Serial1.begin(115200,SERIAL_8N1,U1rxPin,U1txPin);
  while (!Serial1) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // serial print hello world.
  Serial1.println("Hello world!");
}

// the loop routine runs over and over again forever:
void loop() 
{
  // print out the value if Serial available.
  if (Serial1.available() > 0) 
  {
    // get incoming byte:
    inByte = Serial1.read();
    // send back values:
    Serial1.write(inByte);
  }
}
