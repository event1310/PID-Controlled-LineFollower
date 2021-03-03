#include "drive.h"
// function that steers left and right motor sides separately
// by two variables in range -255 to 255
// positive value - go forward
// negative value - go backwards
// value is set to zero - motors off

void SetDrive(int motorL, int motorP)
{
  // left motors
  if(motorL > 0)
  {
    motor1.run(FORWARD); // left front
    motor2.run(FORWARD); // left rear
  }
  else if(motorL < 0)
  {
    motor1.run(BACKWARD); // left front
    motor2.run(BACKWARD); // left rear
  }
  else
  {
    motor1.run(RELEASE); //left front
    motor2.run(RELEASE); // left rear
  }
  if(motorL < 0) motorL *= -1;
  if(motorL > 255) motorL = 255;
  motor1.setSpeed(motorL);
  motor2.setSpeed(motorL);


  // right motors
  if(motorP > 0)
  {
    motor3.run(FORWARD); // right rear
    motor4.run(FORWARD); // right front
  }
  else if(motorP < 0)
  {
    motor3.run(BACKWARD); // right rear
    motor4.run(BACKWARD); // right front
  }
  else
  {    
    motor3.run(RELEASE); // right rear
    motor4.run(RELEASE); // right front
  }
  if(motorP < 0) motorP *= -1;
  if(motorP > 255) motorP = 255;
  motor3.setSpeed(motorP);
  motor4.setSpeed(motorP); 
}

// function that sets motor speed value based on given direction and car max speed
// variable dir -> value from -255 (turn left) to 255 (turn right), 0 (go straight)
// variable speed -> car maxSpeed
void SetDriveForTurning(int speed, int turn)    // dir from updatePID, speed from maxSpeed
{
  SetDrive(speed+turn, speed-turn); // turn left-right
}
