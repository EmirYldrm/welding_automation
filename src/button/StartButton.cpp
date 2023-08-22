#include "StartButton.h"
#include "process/MainProcess.h"


int buttonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 200;
boolean processStatus = false;

void init_start_button()
{
    pinMode(BUTTON_PIN, INPUT);
}


// başlama koşulu belirlenecek.
void debounceHandle()
{
    buttonState = digitalRead(BUTTON_PIN);

  if ( (millis() - lastDebounceTime) > debounceDelay) {

    // Eger butona basılmışsa ve makine çalışır durumda değilse
    if( buttonState  == HIGH && processStatus == false){
      
      Serial.println("BUTONA BASILDI BASLIYOR");
      processStatus = true;
      startProcess();
      lastDebounceTime = millis();
      
    }

    // eger butona basılmışsa ve makine çalışır durumdaysa
    else if (buttonState == HIGH && processStatus == true){

      Serial.println("BUTONA BASILDI BITIRILIYOR");
      // sadece bu flag false yapılarak işlem bitirilebiliyor.
      processStatus = false;
      
      lastDebounceTime = millis();
    
    }
  }
}
