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
    EEPROM.put(EEPROM_ADDRESS, processCounter);
    //Serial.print("toplam basim sayisi: "); Serial.print(processCounter); Serial.println(); 
}
