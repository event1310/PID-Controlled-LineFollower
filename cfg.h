// macro that changes float to Q15 number system
#define Q15(X) ((X < 0.0) ? (int)(32768*(X) - 0.5) : (int)(32767*(X) + 0.5))

// PID controller settings
#define Kp Q15(0.625)
#define Ki Q15(0.1)
#define Kd Q15(0.02)

// max car speed (0-255)
#define maxSpeed 255
