#include <AFMotor.h>

int pindirection = 19;
int pinstart = 18;
int direction;
int start;

void CarBackward(void) 
{
  FollowLine(-1);
}

void CarForward(void)
{
  FollowLine(1);  
}

void CarStop(void) 
{
  SetDrive(0,0);
}

void setup()
{
  Serial.begin(9600);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  digitalWrite(pindirection, HIGH);
  digitalWrite(pinstart, LOW);     
}
void loop() 
{
  static int robot_on_line = 1;
  direction = digitalRead(pindirection);
  start = digitalRead(pinstart); 

  
  if(start)             // if start - robot is on
  {
    robot_on_line = direction ? 1 : -1; // 1 - go forward and use front sensors, -1 go backward and use rear sensors
    SensorsRead(direction);
  } 
  else robot_on_line = 0;

  

// executed every x ms
  static unsigned long tim;
  if(millis() - tim > 20)
  {
    if(robot_on_line > 0) 
    {
      CarForward();
    }
    else if(robot_on_line < 0)   CarBackward();
    else CarStop();  
    tim = millis();
  }
}
