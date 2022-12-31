#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 16);
int sensorPin = A0;
void setup()
{ 
  Serial.begin(9600);
  lcd.begin();
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
 lcd.begin();
lcd.clear();
lcd.setCursor (0,0);
lcd.print("BATCH-7 ");
lcd.setCursor (0,1);
lcd.print("MINIPROJECT"); 
delay(2000);
lcd.clear();
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  int turbidity = map(sensorValue, 0, 355, 130, 0);
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("PURITY:");
  lcd.print("   ");
  lcd.setCursor(10, 0);
  lcd.print(turbidity);
  delay(100);
  if (turbidity < 20) {
    digitalWrite(13, HIGH);
     digitalWrite(12, LOW);
    lcd.setCursor(0, 1);
    lcd.print(" WATER IS PURE");
  }
  
  if (turbidity > 50) {
    digitalWrite(12, HIGH);
     digitalWrite(13, LOW);
 
    lcd.setCursor(0, 1);
    lcd.print("WATER IS NOTPURE");
  }
}
