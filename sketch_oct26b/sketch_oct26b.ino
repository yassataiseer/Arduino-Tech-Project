#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{

  // Robojax code for LCD with I2C
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  // Robojax code for LCD with I2C
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop()
{
   if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value}
   }
  byte x = Serial.read();
  if (x == B00111000)
  { //8
    Weather();
  }
  if (x == B00110010) { //2
    Time101();
  }
  if (x == B00110101) { //5
    Covid();


  }
}

void Weather() {

  //start of loop Robojax code for LCD with I2C
  lcd.clear();
  lcd.print("It is 13 degrees");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("It is hot!");
  //lcd.print(millis() / 1000);
  delay(5);
  lcd.clear();
  delay(5);
}
void Time101() {
  lcd.clear();
  lcd.print("It is 3 O'Clock");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("It is AfterNoon!");
  //lcd.print(millis() / 1000);
  delay(5);
  lcd.clear();
  delay(5);
  //end of loopcode Robojax code for LCD with I2C
}
void Covid() {
  lcd.clear();
  lcd.print("50 cases 3 deaths");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("Covid is stable!");
  //lcd.print(millis() / 1000);
  delay(5);
  lcd.clear();
  delay(5);
}
void Quote() {
  lcd.clear();
  lcd.print("Dwight don't be");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("an idiot-M.G.S");
  //lcd.print(millis() / 1000);
  delay(5);
  lcd.clear();
  delay(5);
}
void Light() {
  lcd.clear();
  lcd.print("Light is on!");
  //lcd.print(millis() / 1000);
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print(":-)");
  delay(5);
  lcd.clear();
  delay(5);
}
