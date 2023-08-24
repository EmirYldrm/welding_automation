#include <Arduino.h>


#include "servo/TourchTrigger.h"
#include "button/StartButton.h"
#include "steppers/SpinTable.h"
#include "steppers/TourchMotor.h"
#include "eeprom/eepromHandler.h"
void setup() {
  
  Serial.begin(9600);
  
  init_EEPROM();
  init_servo_motor();
  init_start_button();
  init_spin_motor();
  init_tourch_motor();
  init_limit_sensor();

}

void loop() {
  debounceHandle();
}

