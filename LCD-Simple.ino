#include <LiquidCrystal.h>

LiquidCrystal lcd (12,11,5,4,3,2);
// Sans boucle
void setup(){
  // lcd.begin(16,2);
  // lcd.setCursor(0, 0); // Line 1
  // lcd.print("message");
  // lcd.setCursor(0, 1); // Line 2
  // lcd.print("Message");
}

// Avec boucle
void loop(){
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("message");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("Message");
  delay(500);
}
