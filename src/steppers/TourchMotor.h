#ifndef TOURCH_MOTOR
#define TOURCH_MOTOR

#include <Arduino.h>
#include <AccelStepper.h>

//E0 MOTORA BAXLANACAK
#define TOURCH_MOTOR_PUL 26
#define TOURCH_MOTOR_DIR 28
#define TOURCH_MOTOR_ENA 24

#define LIMIT_SWITCH_PIN 14 // Y_MIN

#define OPEN_POS_IN_STEPS 400   //farazi bir değer girildi denemelerde düzeltilecek

extern AccelStepper tourchMotor;

void init_limit_sensor();
void init_tourch_motor();
void approachTourch();
void retractTourch();




#endif