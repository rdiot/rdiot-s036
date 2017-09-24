/* Infrared distance sensor (GP2Y0A21YK0F) [S036] : http://rdiot.tistory.com/74 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

int pin = A0;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  pinMode(pin,INPUT);
  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S036:GP2Y0A21YK0F");

  int I = analogRead(pin);
  int value = (6762 /(I-9)) -(4);

  lcd.setCursor(0,1);
  lcd.print("analog=" + (String)I + "   ");
  delay(1000);

  lcd.setCursor(0,2);
  lcd.print("distance=" + (String)value + "CM  ");

}
