#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <dht11.h>
dht11 sensor;
#define DHT11PIN 10
byte degree[8] = // кодируем символ градуса
{
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
};
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.createChar(1, degree); // Создаем символ под номером 1
}
void loop()
{
  int chk = sensor.read(DHT11PIN);
  lcd.setCursor(0, 0);
  lcd.print("Humidity:      %");
  lcd.setCursor(13, 0);
  lcd.print(sensor.humidity);
  lcd.setCursor(0, 1);
  lcd.print("Temperature:   C");
  lcd.setCursor(13, 1);
  lcd.print(sensor.temperature);
  delay(2000);
}
