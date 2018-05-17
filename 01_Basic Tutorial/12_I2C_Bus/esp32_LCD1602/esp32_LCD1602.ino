
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); //设置16位字符和2行显示的LCD地址为0x27

void  setup()
{
  lcd.begin(12,14); //用SDA和SCL引脚初始化lcd 
  //在LCD上打印消息。
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello，world！");
  lcd.setCursor(0,1);
  lcd.print("by EasyIoT");
}

void  loop()
{

}
