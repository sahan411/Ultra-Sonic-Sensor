//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int i, j;
float an;
int x = 0;
int y = 0;
int a, b, c, d;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

byte zero[8] = {B00000,
                B00000,
                B00000,
                B00000,
                B00000,
                B00000,
                B00000,
                B00000
               };

byte one[8] = {B10000,
               B10000,
               B10000,
               B10000,
               B10000,
               B10000,
               B10000,
               B10000
              };

byte two[8] = {B11000,
               B11000,
               B11000,
               B11000,
               B11000,
               B11000,
               B11000,
               B11000
              };

byte three[8] = {B11100,
                 B11100,
                 B11100,
                 B11100,
                 B11100,
                 B11100,
                 B11100,
                 B11100
                };

byte four[8] = {B11110,
                B11110,
                B11110,
                B11110,
                B11110,
                B11110,
                B11110,
                B11110
               };

byte five[8] = {B11111,
                B11111,
                B11111,
                B11111,
                B11111,
                B11111,
                B11111,
                B11111
               };

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init(); // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.createChar(0, zero);
  lcd.createChar(1, one);
  lcd.createChar(2, two);
  lcd.createChar(3, three);
  lcd.createChar(4, four);
  lcd.createChar(5, five);
  Serial.begin(9600);
}


void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if(distance > 50){
    distance = 50;
  }
  if (distance > 2) {
    x = map(distance, 50, 3, 80, 0);
    a = x / 5;
    b = x - (a * 5);

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");

    lcd.setCursor(0, 0);
    lcd.print("Distance : ");
    if(distance<10){
      lcd.print("0");
    }
    lcd.print(distance);
    lcd.print(" cm");

    i = 0;
    while (i < a) {
      lcd.setCursor(i, 1); // set cursor till full box
      lcd.write(5);
      i = i + 1;
    }

    lcd.setCursor(i, 1);
    lcd.write(b);
    lcd.print("                 ");
  }

}
