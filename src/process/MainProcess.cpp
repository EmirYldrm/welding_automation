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

void startProcess()
{   
    approachTourch();
    openTourch();
    spinCW();
    closeTourch();
    retractTourch();

    processStatus == false;
    
    return;
}

void cancelProcess()
{
     closeTourch();
     stopSpinMotor();
     retractTourch();

     return;
}
