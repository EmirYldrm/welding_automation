#ifndef SERVO_MOTOR
#define SERVO_MOTOR

#include <Servo.h>
# define SERVO_PIN 3    // X_MIN

extern Servo triggerServo;
extern int pos;

void init_servo_motor();
void openTourch();
void closeTourch();


#endif