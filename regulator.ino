#include "cfg.h"

#define outMin -255
#define outMax 255

int16_t updatePID(int16_t in, int16_t target)
{
  static int16_t errorLast = 0;    // previous error
  static int32_t integral = 0;     // integral
  int16_t pTerm, iTerm, dTerm, error;

  // P
  error = target - in;
  pTerm = ((int32_t)Kp * error)/32767;

  // I
  integral += error;
  if(integral > 10000) integral = 10000;
  if(integral < -10000) integral = -10000;
  iTerm = ((int32_t)Ki *  integral)/32767;

  // D
  dTerm = ((int32_t)Kd * (error - errorLast))/32767;
  errorLast = error;

  // out calc
  int32_t out;
  out = (int32_t)pTerm + iTerm + dTerm;
  if(out > outMax) out = outMax;
  if(out < outMin) out = outMin;
  return out;
}
