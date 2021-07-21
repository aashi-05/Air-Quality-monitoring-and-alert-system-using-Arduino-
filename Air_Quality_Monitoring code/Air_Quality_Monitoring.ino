#include <LiquidCrystal.h>
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int buz=8;
int led=9;
const int mqsensor=A0;
int threshold=250;
void setup() {
  pinMode(buz,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(mqsensor,INPUT);

  Serial.begin(9600);//setting baud rate to display the value on lcd.

  lcd.clear();//clear the lcd screen.
  lcd.begin(16, 2);
  
}

void loop() {
  int ppm=analogRead(mqsensor);
  Serial.print("Air Quality: ");
  Serial.println(ppm);

  lcd.setCursor(0,0);//set the cursor to first row, first column.
  lcd.print("Air Quality: ");
  lcd.print(ppm);

  if(ppm > threshold){
    lcd.setCursor(1,1);
    lcd.print("Pollution level HIGH!!");
    Serial.print("Pollution level HIGH!!");
    tone(led,1000,200);//used for blinking LED.
    digitalWrite(buz,HIGH);//turn on the buzzer.
  }
  else{
    digitalWrite(led,LOW);
    digitalWrite(buz,LOW);
    lcd.setCursor(1,1);
    lcd.print("Air Quality Good");
    Serial.print("Air Quality GOOD!!");
  }
  delay(500);
}
