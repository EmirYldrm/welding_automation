#ifndef START_BUTTON
#define START_BUTTON

#include <Arduino.h>
#include "steppers/SpinTable.h"
#include "servo/TourchTrigger.h"


#define BUTTON_PIN 19   //Z_MAX

extern int buttonState;
extern long lastDebounceTime;
extern long debounceDelay;
extern boolean processStatus;

void init_start_button();
void debounceHandle();

#endif