#include <AFMotor.h>

int pinkierunek = 19;
int pinstart = 18;
int kierunek;
int start;

void CarBackward(void) 
{
  FollowLine(-1);
}
//asd
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
  digitalWrite(pinkierunek, HIGH);
  digitalWrite(pinstart, LOW);     
}
void loop() 
{
    static int robot_na_linii = 1;
  kierunek = digitalRead(pinkierunek);
  start = digitalRead(pinstart); 

  
  if(start)             // decyduje o włączeniu
  {
    robot_na_linii = kierunek ? 1 : -1; // stopstan - zmienione na kierunek decyduje o kierunku jazdy
    SensorsRead(kierunek);
  } 
  else robot_na_linii = 0;

  

// wykonywane co x ms - ma wpływ na działanie regulatora PID!
  static unsigned long tim;
  if(millis() - tim > 20)
  {
    if(robot_na_linii > 0) 
    {
      CarForward();
      Serial.println("forward"); 
    }
    else if(robot_na_linii < 0)   CarBackward();
    else CarStop();  
    tim = millis();
  }
}
