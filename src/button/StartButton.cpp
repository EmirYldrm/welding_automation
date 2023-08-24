#include "StartButton.h"
#include "process/MainProcess.h"
#include "eeprom/eepromHandler.h"

int buttonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 500;
volatile boolean processStatus = false;

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
    if( buttonState  == LOW && processStatus == false){
      
      Serial.println("BUTONA BASILDI BASLIYOR");

      processStatus = true;
      startProcess();   // işlemi başlatıyoruz
      processStatus = false;

      updateCounter();  // eeproma kayıtlı counter her döngüde artırıyoruz.
      
      Serial.println(processCounter); // sayaç seri ekrana yazdırılıyor.

    }

    // eger butona basılmışsa ve makine çalışır durumdaysa
    else if (buttonState == LOW && processStatus == true){

      Serial.println("BUTONA BASILDI BITIRILIYOR");
      Serial.println(processStatus);

      // sadece bu flag false yapılarak işlem bitirilebiliyor.
      processStatus = false;
  
    
    }
    lastDebounceTime = millis();
  }
}
