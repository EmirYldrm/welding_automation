#include "eepromHandler.h"

int processCounter;

void init_EEPROM()
{
    processCounter = 0;
    EEPROM.get(EEPROM_ADDRESS, processCounter);

}

void updateCounter()
{
    processCounter++;
    EEPROM.write(EEPROM_ADDRESS, processCounter);
}
