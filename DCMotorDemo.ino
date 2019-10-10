//  Demo function:The application method to drive the DC motor.
//  Author:Frankie.Chu
//  Date:20 November, 2012

#include "MotorDriver.h"
const int pingPin = 5;
int inPin = 3;
void setup()
{
  Serial.begin(9600);
  /*Configure the motor A to control the wheel at the left side.*/
  /*Configure the motor B to control the wheel at the right side.*/
  motordriver.init();
  motordriver.setSpeed(200, MOTORB);
  motordriver.setSpeed(200, MOTORA);
}

void loop()
{
  long duration, cm;

  pinMode(pingPin, OUTPUT);


  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm < 50) {
    motordriver.stop();
    delay(100);
  }
  else if(cm>=50) {
    motordriver.goForward();
    delay(100);
  }

  //	delay(2000);
  //	motordriver.stop();
  //	delay(1000);
  //	motordriver.goBackward();
  //	delay(2000);
  //	motordriver.stop();
  //	delay(1000);
  //	motordriver.goLeft();
  //	delay(2000);
  //	motordriver.stop();
  //	delay(1000);
  //	motordriver.goRight();
  //	delay(2000);
  //	motordriver.stop();


}
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
