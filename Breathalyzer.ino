#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int MQ3=0;
const int Buzzer=8;
const int LED=9;
const int MOTOR=12;
int value;

void setup() {
	Serial.begin(9600);
  lcd.begin(16,2);
	pinMode(MQ3, INPUT);
	pinMode(Buzzer, OUTPUT);
	pinMode(LED, OUTPUT);
  pinMode(MOTOR, OUTPUT);
	digitalWrite(Buzzer,LOW);
	digitalWrite(LED,LOW);
  digitalWrite(MOTOR,HIGH);

}

void loop()
{
	value= analogRead(MQ3);
  lcd.print("Alcohol Lev.:");
  lcd.print(value);
	Serial.println(value);
  
	if(value>690)
	{
		digitalWrite(Buzzer,HIGH);
		digitalWrite(LED,HIGH);
    digitalWrite(MOTOR,LOW);
    lcd.setCursor(0, 2);
    lcd.print("Alert....!!!");
    Serial.print ("Alert");   
    delay(1000);
	}else{
		digitalWrite(Buzzer,LOW);
		digitalWrite(LED,LOW);
    digitalWrite(MOTOR,HIGH);
    lcd.setCursor(0, 2);
    lcd.print(".....Normal.....");
    Serial.print("Normal");
	}

	delay (100);
}
