/*
                    EMİR YILDIRIM - AKİL ENDÜSTRİ 
                      KAYNAK MAKİNESİ OTOMASYONU
  Bu projede;
  ->  Kaynatılacak parçayı döndürmek üzere bir adet NEMA 23 step motor,
  ->  Kaynak makinesini yaklaştırmak için bir adet NEMA 17 step motor,
  ->  Kaynak makinesinin min pozisyonunu bilebilmesi için mekanik limit switch,
  ->  Kaynak makinesinin tetiğine basması için kullanılan MG SERVO motor,
  ->  Kaynak işlemini başlatmak için bir adet buton (INPUT_PULLUP) 
  ->  Kaynak işelemi yapılırken döner tablanın hızını ayarlamak için potansiyometre
  kullanılmıştır.
  (With contribution by M. Erol Gencay)
 */

#include <Arduino.h>

#include "servo/TourchTrigger.h"
#include "button/StartButton.h"
#include "steppers/SpinTable.h"
#include "steppers/TourchMotor.h"
#include "eeprom/eepromHandler.h"
#include "tourch_relay/TourchHandler.h"

void setup() {
  
  Serial.begin(9600);

  init_EEPROM();
  init_tourch_relay();
  //init_servo_motor();
  init_start_button();
  init_spin_motor();
  init_tourch_motor();
  init_limit_sensor();

}

void loop() {
  debounceHandle();
}

