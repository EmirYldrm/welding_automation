#ifndef TOURCH_HANDLER
#define TOURCH_HANDLER
/**
 * @file TourchHandler.h
 * @author Emir Yıldırım
 * @version 0.1
 * @date 2023-12-15
 * 
 * @copyright Akil Endüstri Copyright (c) 2023
 * 
 *  Torç servo motor yerine direk torç üzerindeki tetiğe röle bağlanarak kontrol edilecek.
 *  
 * 
 */


#include <Arduino.h>

#define RELAY_PIN 3   //Z_MAX


void init_tourch_relay();
void openTourchRelay();
void closeTourchRelay();

#endif