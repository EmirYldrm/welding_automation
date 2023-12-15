/*  servo ac
    motor dondüür
    torc yaklaşcak
    toruc geri çek
    */
#include "MainProcess.h"
#include "steppers/SpinTable.h"
#include "steppers/TourchMotor.h"
#include "servo/TourchTrigger.h"
#include "button/StartButton.h"
#include "tourch_relay/TourchHandler.h"

void startProcess()
{   
    approachTourch();
    //openTourch();
    openTourchRelay();
    spinCW();
    //closeTourch();
    closeTourchRelay();
    retractTourch();

    return;
}

void cancelProcess()
{
     //closeTourch();
     closeTourchRelay();
     stopSpinMotor();
     retractTourch();

     return;
}
