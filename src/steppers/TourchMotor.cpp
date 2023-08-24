#include "TourchMotor.h"

AccelStepper tourchMotor(1, TOURCH_MOTOR_PUL, TOURCH_MOTOR_DIR);

void init_limit_sensor()
{
    pinMode(LIMIT_SWITCH_PIN, INPUT_PULLUP);
}

void init_tourch_motor()
{
    tourchMotor.setMaxSpeed(1000);
    tourchMotor.setAcceleration(1000);
    tourchMotor.setSpeed(1000);
    tourchMotor.setCurrentPosition(0);

    pinMode(TOURCH_MOTOR_ENA, OUTPUT);

}

void approachTourch()
{   
    

    // Motor enable edildi
    digitalWrite(TOURCH_MOTOR_ENA, LOW);
    
    delay(100);
    while(digitalRead(LIMIT_SWITCH_PIN) == HIGH){
      tourchMotor.setSpeed(1000);  
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


    tourchMotor.move(-OPEN_POS_IN_STEPS);
    tourchMotor.setMaxSpeed(100);
    delay(100);
    tourchMotor.runToPosition();
    delay(100);
    tourchMotor.setCurrentPosition(0);

    // Motor disable edildi
    digitalWrite(TOURCH_MOTOR_ENA, HIGH);


}
