#include<LiquidCrystal.h>
int echopin = 13;
int trigpin = 12;
float duration =0.0;
float cm =0.0;
LiquidCrystal lcd(11,10,2,3,4,5);

void setup() {
  lcd.begin(16,2);
  pinMode(echopin,INPUT);
  pinMode(trigpin,OUTPUT);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delay(2);

  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigpin,LOW);

  duration = pulseIn(echopin,HIGH);

  cm = (duration * 0.034)/2;

  lcd.setCursor(0,0);
  lcd.print("Dis: ");
  lcd.print(cm);
  lcd.print(" cm");
  delay(1000);

}
