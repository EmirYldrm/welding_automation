#include "steppers/TourchMotor.h"
#include "TourchMotor.h"

AccelStepper tourchMotor(1, TOURCH_MOTOR_PUL, TOURCH_MOTOR_DIR);
void init_limit_sensor()
{
    pinMode(LIMIT_SWITCH_PIN, INPUT_PULLUP);
}

void init_tourch_motor()
{
    tourchMotor.setMaxSpeed(200);
    tourchMotor.setAcceleration(200);
    tourchMotor.setSpeed(200);
    tourchMotor.setCurrentPosition(0);

    pinMode(TOURCH_MOTOR_ENA, OUTPUT);
    // Motor enable edildi
    digitalWrite(TOURCH_MOTOR_ENA, LOW);
}

void approachTourch()
{   
    Serial.println("TORC YAKLASTIRILDI");

    // Motor enable edildi
    digitalWrite(TOURCH_MOTOR_ENA, LOW);
    
    delay(100);
    while(digitalRead(LIMIT_SWITCH_PIN) == 0){
      tourchMotor.setSpeed(100);  
      tourchMotor.runSpeed();
    }
    tourchMotor.setCurrentPosition(0);
    delay(100);
}

void retractTourch()
{
    Serial.println("TORC UZAKLASTIRILDI");

    // Motor enable edildi
    digitalWrite(TOURCH_MOTOR_ENA, LOW);


    tourchMotor.move(OPEN_POS_IN_STEPS);
    tourchMotor.setMaxSpeed(200);
    delay(100);
    tourchMotor.runToPosition();
    delay(100);
    tourchMotor.setCurrentPosition(0);


}
