//this is a binary reader
#include <LiquidCrystal.h> 

int setdigit1 = A0;
int setdigit2 = A1; 
//had to change these because each time I restarted, one of the LED would not switch
int setdigit3 = 10;
int setdigit4 = 7;

int setled1 = A2;
int setled2 = A3;
int setled3 = A4;
int setled4 = A5;
 
// (RS, Enable, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("helllo");
  
  pinMode(setdigit1, INPUT_PULLUP);
  pinMode(setdigit2, INPUT_PULLUP);
  pinMode(setdigit3, INPUT_PULLUP);
  pinMode(setdigit4, INPUT_PULLUP);

  pinMode(setled1, OUTPUT);
  pinMode(setled2, OUTPUT);
  pinMode(setled3, OUTPUT);
  pinMode(setled4, OUTPUT);
}

void loop() {
  lcd.setCursor(0, 0);

  //get numbers
  int digit1 = digitalRead(setdigit1);
  int digit2 = digitalRead(setdigit2);
  int digit3 = digitalRead(setdigit3);
  int digit4 = digitalRead(setdigit4);

  digitalWrite(setled1, digit1);
  digitalWrite(setled2, digit2);
  digitalWrite(setled3, digit3);
  digitalWrite(setled4, digit4);


  lcd.print("NUMBERS:");
  lcd.print(digit1);
  lcd.print(digit2);
  lcd.print(digit3);
  lcd.print(digit4);

  int value = (digit1 * 8) + (digit2 * 4) + (digit3 * 2) + (digit4 * 1);

  lcd.setCursor(0, 1);
  lcd.print("DECODED:");
  lcd.print(value);

  delay(10);
  lcd.clear();
}
