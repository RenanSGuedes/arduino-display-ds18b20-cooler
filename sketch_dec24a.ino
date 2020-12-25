#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h> 
#include <LiquidCrystal_I2C.h>

#define DS18B20 7

OneWire ourWire(DS18B20);
DallasTemperature sensors(&ourWire);

//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);
 
void setup(){
 lcd.init();

 Serial.begin(9600);
 sensors.begin();
 delay(1000);
}
 
void loop()
{
  sensors.requestTemperatures();
   
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);  
  delay(250);

}
