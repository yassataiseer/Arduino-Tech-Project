#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup()
{

  // Robojax code for LCD with I2C
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  // Robojax code for LCD with I2C
  Serial.begin(9600);

}

void loop()
{
  char key = keypad.getKey();

  if (key == '1')
  { //8
    Weather();
    delay(5);
    cleanout();
  }
      if (key == '2')
  { //8
    Quote();
    delay(5);
    cleanout();
  }
  
    if (key == '4')
  { //8
    Time101();
    delay(5);
    cleanout();
  }
      if (key == '5')
  { //8
    Light();
    delay(5);
    cleanout();

  }
  
    if (key == '7')
  { //8
    Covid();
    delay(5);
    cleanout();
  }
      if (key == '8')
  { //8
    Call_mom();
    delay(5);
    cleanout();
  }
      if (key == '3')
  { //8
    Stock();
    delay(5);
    cleanout();
  }

      if (key == '6')
  { //8
    Garage();
    delay(5);
    cleanout();
  }

  }

void cleanout(){
    lcd.clear();
  }
void Weather() {

  //start of loop Robojax code for LCD with I2C
  lcd.clear();
  delay(5);
  lcd.print("It is 13 degrees");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("It is hot!");
  //lcd.print(millis() / 1000);
  //delay(500);
  delay(1000);
}
void Time101() {
  lcd.clear();
  delay(5);
  lcd.print("It is 3 O'Clock");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("It is AfterNoon!");
  //lcd.print(millis() / 1000);
  delay(1000);
  //end of loopcode Robojax code for LCD with I2C
}
void Covid() {
  lcd.clear();
  delay(5);
  lcd.print("50 cases 3 deaths");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("Covid is stable!");
  //lcd.print(millis() / 1000);
  delay(1000);
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
  delay(1000);
}

void Call_mom() {
  lcd.clear();
  delay(5);
  lcd.print("Calling Mom!");
  //lcd.print(millis() / 1000);
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("647-420-6090");
  delay(1000);
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
  delay(1000);
}
