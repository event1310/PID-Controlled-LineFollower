//#include "sensors.h"


void SensorsRead(int kierunek)
{
  if(kierunek > 0)
  {
    left_sensor_state = digitalRead(left_sensor_pin);
    right_sensor_state = digitalRead(right_sensor_pin);
  }
  else 
  {
    left_sensor_state = digitalRead(back_left_sensor_pin);
    right_sensor_state = digitalRead(back_right_sensor_pin);
  }
}
  
int PositionRead(void)
{
  // is left sensor on the line?
  if(!left_sensor_state) 
  {
    if(!right_sensor_state)     return 0;  // both sensors on the line
    else                            return -1; // only left sensor on the line
  }
  // is right sensor on the line?
  else if(!right_sensor_state)  return 1;  // only right sensor on the line
  else                              return 2;  // none of the sensors on the line (memory)
}    
