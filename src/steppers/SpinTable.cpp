#include "SpinTable.h"
#include "potansiyometer/SpeedPot.h"
#include "button/StartButton.h"

#define NUM_STEPS 6400

AccelStepper spinMotor(1, SPIN_MOTOR_PUL, SPIN_MOTOR_DIR);


void init_spin_motor()
{
    //spinMotor.setEnablePin(SPIN_MOTOR_ENA);
    spinMotor.setMaxSpeed(2000);
    spinMotor.setAcceleration(2000);
    spinMotor.setSpeed(2000);
    pinMode(SPIN_MOTOR_ENA, OUTPUT);
    digitalWrite(SPIN_MOTOR_ENA, LOW);
    //spinMotor.enableOutputs();
}

void spinCW()
{
    Serial.println("TABLA DONUYOR");
  
  //delay(1000);
  digitalWrite(SPIN_MOTOR_ENA, LOW);
  spinMotor.move(NUM_STEPS);

  while(spinMotor.currentPosition() != NUM_STEPS && processStatus == true){

    int potValue = (int) readPotVaules();

    // Potansiyometre değerini hız aralığına dönüştürün
    // Örneğin, 0-1023 arasındaki analog değeri 1000-2000 adım/s arasındaki hıza dönüştürebilirsiniz
    float speed = potValue * 2; // map(potValue, 0, 1023, 0, 5000);


    // Adım motorunun hızını güncelleyin
    spinMotor.setSpeed(speed);

    //Serial.println(speed);

    // Adım motorunu belirtilen hızda hareket ettirin
    spinMotor.runSpeed();

    // debaunce handle butonu okumamız lazım
    debounceHandle();
  }
  spinMotor.setCurrentPosition(0);
  delay(1000);
 Serial.println("TABLA DONME ISLEMI BITTI");
  return;
}

void spinCCW()
{
   spinMotor.move(-NUM_STEPS);

  while(spinMotor.currentPosition() != -NUM_STEPS){

    int potValue = (int) readPotVaules();

    // Potansiyometre değerini hız aralığına dönüştürün
    // Örneğin, 0-1023 arasındaki analog değeri 1000-2000 adım/s arasındaki hıza dönüştürebilirsiniz
    float speed = map(potValue, 0, 1023, 0, 1000);

    // Adım motorunun hızını güncelleyin
    spinMotor.setSpeed(speed);

    // Adım motorunu belirtilen hızda hareket ettirin
    spinMotor.runSpeed();
  }
  return;
}

void stopSpinMotor()
{
    spinMotor.stop();
    spinMotor.setCurrentPosition(0);
    return;
}
