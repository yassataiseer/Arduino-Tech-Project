

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int RECV_PIN = 7;
int buzzer = 13; // The pin for where the buzzer is found
int LED = 11;


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(buzzer,OUTPUT);

  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

}

void loop()
{
  char key = keypad.getKey();

  if (key == '1')
  { //8
    Weather();
    delay(50);
    cleanout();
  }
      if (key == '2')
  { //8
    Quote();
    delay(50);
    cleanout();
  }
  
    if (key == '4')
  { //8
    Time101();
    delay(50);
    cleanout();
  }
      if (key == '5')
  { //8
    Light();
    delay(50);
    cleanout();

  }
  
    if (key == '7')
  { //8
    Covid();
    delay(50);
    cleanout();
  }
      if (key == '8')
  { //8
    Call_mom();
    delay(50);
    cleanout();
  }
      if (key == '3')
  { //8
    Stock();
    delay(50);
    cleanout();
  }

      if (key == '6')
  { //8
    Garage();
    delay(5);
    cleanout();
  }
      if (key == '9')
  { //8
    off_light();
    delay(50);
    cleanout();
  }
        if (key == 'D')
  { 
    song();
  for (int i = 0; i < 2; i++) {
    firstSection();
     secondSection();
  }
  cleanout();
  }
  
  }

void cleanout(){//Clears lines after displaying something
    lcd.clear();
  }
void Weather() {//Shows The Weather

  //start of loop Robojax code for LCD with I2C
  lcd.clear();
  delay(5);
  lcd.print("It is 13 degrees");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("It is hot!");
  //lcd.print(millis() / 1000);
  //delay(500);
  delay(2000);
}
void Time101() {//Tells The Time
  lcd.clear();
  delay(5);
  lcd.print("It is 3 O'Clock");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("It is AfterNoon!");
  //lcd.print(millis() / 1000);
  delay(2000);
  //end of loopcode Robojax code for LCD with I2C
}
void Covid() {
  lcd.clear();
  delay(5);
  lcd.print("50 cases 3 deaths");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("Covid is stable!");
  //lcd.print(millis() / 1000);
  delay(2000);
}
void Quote() {
  lcd.clear();
   delay(5);
  lcd.print("Dwight don't be");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("an idiot-M.G.S");
  //lcd.print(millis() / 1000);
  delay(1000);
}
void Light() {
  lcd.clear();
  delay(5);
  lcd.print("Light is on!");
  //lcd.print(millis() / 1000);
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print(":-)");
  on_light();
  delay(2000);
}

void Call_mom() {
  lcd.clear();
  delay(5);
  lcd.print("Calling Mom!");
  //lcd.print(millis() / 1000);
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("647-420-6090");
  Music();
}

void Stock() {
  lcd.clear();
  delay(5);
  lcd.print("Stock From NYSE:!");
  //lcd.print(millis() / 1000);
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("AAPL +44.5");
  delay(1000);
}

void Garage() {
  lcd.clear();
  delay(5);
  lcd.print("Opening Garage!");
  //lcd.print(millis() / 1000);
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("*Garage noises*");
  Music();
}

void Music(){//Buzzer Function
  int i = 0;
  while (i<10){
    i++;
    digitalWrite(buzzer,HIGH);
    delay(1);
    digitalWrite(buzzer,LOW); 
    delay(1000); 
    }
  }


void on_light(){
  digitalWrite(LED, HIGH);
  }

void off_light(){
  lcd.print("Turning off the");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("light :)");
  digitalWrite(LED,LOW);
  delay(2000);
  }

void song(){
  lcd.print("Playing Song");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print(":)");
  delay(2000);
  }

void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
}

 
void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
}




void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzer,note,duration);
}
