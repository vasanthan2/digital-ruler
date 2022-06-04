
#include <LiquidCrystal.h>
#define echoPin 14
#define trigPin 15
char * mes = "    https://github.com/vasanthan2  ";
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
long duration;
int inc;
int distance;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  
}
void loop() {
  for (int letter = 0; letter <= strlen(mes) - 16; letter++) 
  {
    showLetters(0, letter);
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034 / 2);

  inc = (distance / 2.54);

  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.println(" cm     ");
  lcd.setCursor(8, 1);
  lcd.print(inc);
  lcd.println(" inc     ");

    Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm ");
 

  }
  




  
}
void showLetters(int printStart, int startLetter)
{
  lcd.setCursor(printStart, 0);
  for (int letter = startLetter; letter <= startLetter + 15; letter++) // Print only 16 chars in Line #2 starting 'startLetter'
  {
    lcd.print(mes[letter]);
  }
  lcd.print(" ");
  delay(250);
}
