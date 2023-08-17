#ifndef START_BUTTON
#define START_BUTTON

#include <Arduino.h>
#include "steppers/SpinTable.h"
#include "servo/TourchTrigger.h"


#define BUTTON_PIN 19

extern int buttonState;
extern long lastDebounceTime;
extern long debounceDelay;

void init_start_button();
void debounceHandle();

#endif