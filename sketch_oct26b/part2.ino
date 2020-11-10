#include <Servo.h>
#define SERVO_PIN 9
#define GROUND_JOY_PIN A3            //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2              //joystick +5 V pin will connect to Arduino analog pin A2
#define XJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1
Servo myservo ;
int red_light_pin= 5;
int green_light_pin = 6;
int blue_light_pin = 7;
void setup()
{
 Serial.begin(9600);
 pinMode(VOUT_JOY_PIN, OUTPUT) ;    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN, OUTPUT) ;  //pin A2 shall be used as output
 pinMode(red_light_pin,OUTPUT);
 pinMode(green_light_pin,OUTPUT);
 pinMode(blue_light_pin,OUTPUT);
 digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN,LOW) ; //set pin A3 to low (ground)
 myservo.attach(9);
}
 
void loop()
{
 delay(200);                    
 int joystickXVal = analogRead(XJOY_PIN) ;  //read joystick input on pin A1
 Serial.print(joystickXVal);                //print the value from A1
 Serial.print((joystickXVal+520)/10);       //print a from A1 calculated, scaled value
 myservo.write((joystickXVal+520)/10);      //write the calculated value to the servo  
if(joystickXVal>103){
  RGB_color(255, 255, 0);
  }
else{
  RGB_color(0,0,255);
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
