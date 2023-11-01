#include <LiquidCrystal_I2C.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <Servo.h>

int servoPin = 9;
int servoPos = 180;
int servoPos2 = 0;

Servo myServo;

LiquidCrystal_I2C lcd(0x27, 16, 2);   //LCD Object

ThreeWire myWire(7, 6, 8);        // DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);    // RTC Object

void setup ()
{
  lcd.clear();
  myServo.attach(servoPin); 
  myServo.write(servoPos2);
  Rtc.Begin();
  lcd.init();
  //CORRER 1 VEZ  PROGRAMACION HORA

RtcDateTime currentTime = RtcDateTime(_DATE_ , _TIME_);
Rtc.SetDateTime(currentTime);


  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("DISPENSADOR JUAN");
  delay(2000);
  
}

void loop ()
{
  RtcDateTime now = Rtc.GetDateTime();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fecha:");
  lcd.print(now.Day());
  lcd.print("/");
  lcd.print(now.Month());
  lcd.print("/");
  lcd.print(now.Year());

  lcd.setCursor(0, 1);
  lcd.print("Hora:");
  lcd.print(now.Hour());
  lcd.print(":");
  lcd.print(now.Minute());
  lcd.print(":");
  lcd.print(now.Second());
  
  delay(1000);

  lcd.clear();
  int hora = now.Hour();
  int minuto = now.Minute();
  int segundo = now.Second();


//FUNCION HORA DE ENCENDIDO PROGRAMADA
if (hora == 10 && minuto == 00 && segundo == 00  )
  {
    myServo.write(servoPos);
  lcd.setCursor(0, 1);
  lcd.print("SIRVIENDO COMIDA ");
  delay(1000);
    
    }
else 
 {
    myServo.write(servoPos2);
     }


if (hora == 17 && minuto == 00 && segundo == 00  )
  {
    myServo.write(servoPos);
  lcd.setCursor(0, 1);
  lcd.print("SIRVIENDO COMIDA ");
  delay(1000);
    
    }
else 
 {
    myServo.write(servoPos2);
     }


if (hora == 21 && minuto == 00 && segundo == 00  )
  {
    myServo.write(servoPos);
  lcd.setCursor(0, 1);
  lcd.print("SIRVIENDO COMIDA ");
  delay(1000);
    
    }
else 
 {
    myServo.write(servoPos2);
     }

}
