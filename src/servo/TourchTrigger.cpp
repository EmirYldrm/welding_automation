#include "TourchTrigger.h"
#include <Arduino.h>

Servo triggerServo;

int pos = 0;

void init_servo_motor()
{   
    triggerServo.write(40);
    triggerServo.attach(SERVO_PIN);
}

void openTourch()
{
    Serial.println("TORC ACILDI");

    /*for (pos = 0; pos <= 70; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        triggerServo.write(pos);              // tell servo to go to position in variable 'pos'
                          // waits 15 ms for the servo to reach the position
    }*/
    triggerServo.write(12);
    Serial.println("TORC ACILMASI BITTI ");
}

void closeTourch()
{
    Serial.println("TORC KAPANDI");
    /*
    for (pos = 70; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        triggerServo.write(pos);              // tell servo to go to position in variable 'pos'
                              // waits 15 ms for the servo to reach the position
    }
    */
   triggerServo.write(40);
}
