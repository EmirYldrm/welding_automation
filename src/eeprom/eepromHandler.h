#ifndef EEPROM_HANDLER
#define EEPROM_HANDLER
#include <Arduino.h>
#include <EEPROM.h>

#define EEPROM_ADDRESS 0

extern int processCounter;


void init_EEPROM();
void updateCounter();

#endif