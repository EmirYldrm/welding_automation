#ifndef SPIN_MOTOR
#define SPIN_MOTOR

#include <Arduino.h>
#include <AccelStepper.h>

//Z MOTORA BAXLANACAK
#define SPIN_MOTOR_PUL 26
#define SPIN_MOTOR_DIR 28
#define SPIN_MOTOR_ENA 30

#define STEP_PER_REV 200

extern AccelStepper spinMotor;

void init_spin_motor();

void spinCW();
void spinCCW();
void stopStepper();

#endif