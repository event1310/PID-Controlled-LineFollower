// define sensors
const int back_left_sensor_pin = 14;
const int left_sensor_pin = 15;
const int back_right_sensor_pin = 16;
const int right_sensor_pin = 17;

// actual sensor readings
int left_sensor_state;
int right_sensor_state;

// line detecting threshold
#define thrSens 500
