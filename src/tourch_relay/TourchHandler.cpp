#include "TourchHandler.h"

void init_tourch_relay()
{
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);
}

void openTourchRelay()
{
    digitalWrite(RELAY_PIN, LOW);
}

void closeTourchRelay()
{
    digitalWrite(RELAY_PIN, HIGH);  
}
