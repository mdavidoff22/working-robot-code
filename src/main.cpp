#include <Arduino.h>
#include <Servo.h>
//imports for arduino and servo libraries

Servo servoLeft;
//declare the right and left servos                      
Servo servoRight;

void setup() //a setup function that runs once when defined (so nothing needs to be called in main loop)
{ 
  servoLeft.attach(13);
  //associate the signal of pin 13 with that of the left servo
  servoRight.attach(12);
  //same but for the right servo

  //a 2 second delay such that when the code is reset on the hardware, I have two seconds to adjust the position of the robot before it moves
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  //1500 microseconds corresponds to the wheels not moving
  delay(2000);
  //do this for 2 seconds

  //Note: I move the robot backwards, such that the right and left servo microseconds are flipped from what they usually are when moving in a straight line forwards

  //Move forwards a certain distance before adjusting path
  servoLeft.writeMicroseconds(1300);
  //left wheel to move in the clockwise direction at full speed (which is 1300 microseconds for pin 13 conections)
  servoRight.writeMicroseconds(1700);
  //right wheel to move in the counterclockwise direction at full speed (which is 1300 microseconds for pin 13 conections)
  delay(7300);
  //power the servos at these speeds/directions for 7.3 second

  //Turn right in place (as a slight path adjustment from point A going to B)
  servoLeft.writeMicroseconds(1700);
  //make the left servo turn backwards
  servoRight.writeMicroseconds(1700);
  //while the right servo still moves forwards
  delay(85);
  //do this for 0.085 seconds
  
  //Continue to move forwards for another 7.3 seconds
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(7300);

  //Turn right in place for 0.985 seconds (turning in box B)
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1700);
  delay(985);
  
  //Move forwards for 7.3 seconds before adjusting
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(7300);

  //Turn right in place for 0.092 seconds (as a slight path adjustment from point B going to C)
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1700);
  delay(92);
  
  //my robot is 
  //Move forwards for 12 more seconds (to point C)
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(12000);

  //Turn left for .985 seconds (in box C)
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(985);

  //Move forwards for 13.2 seconds to box D from C
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(13200);

  //after the final forward movement is done, stop the wheels from moving by cutting the signals to pins 12 and 13
  servoLeft.detach();
  servoRight.detach();
}

//again, empty loop as the above function is run once when the code runs
void loop()
{
}