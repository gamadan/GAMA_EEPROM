/*
 * GAMA_EEPROM.h
 *
 * Created: 7/1/2022
 *  Author: Daniel Nebert
 *  Owner: GAMA Electronics, Inc.
 *
 */ 
#ifndef GAMA_EEPROM_H_
#define GAMA_EEPROM_H_

#include "Arduino.h"
#include <EEPROM.h>

#define EEPROM_SIZE					512

#define CHANNEL_DEFAULT_VALUES      "9999"
#define CHANNEL_START_ADDRESS       50
#define CHANNEL_LENGTH              4

#define PASSWORD_DEFAULT_VALUES     "default"
#define PASSWORD_LENGTH_ADDRESS     0
#define PASSWORD_ADDRESS_START      1
#define PASSWORD_MAX_CHARACTERS     50

#define DATA_PIN_ADDRESS            54
#define SELECTOR_PIN_ADDRESS        55
#define RSSI_INPUT_PIN_ADDRESS      56

class GAMA_EEPROM {
  public:
    GAMA_EEPROM();
    void begin();
    std::string initChannelValues();
    
    void saveChannelValues(std::string v);
    std::string loadChannelValues();
    bool hasChannelValues();

    std::string initPassword();

    bool isValidPassword(std::string pw);
    void savePassword(std::string pw);
    std::string loadPassword();
    bool hasEmptyPassword();
    void savePasswordLength(uint8_t l);

    

    uint8_t getDataPin();
    uint8_t getSelectorPin();
    uint8_t getRSSIInputPin();

    void setDataPin(uint8_t p);
    void setSelectorPin(uint8_t p);
    void setRSSIInputPin(uint8_t p);
  private:
    int size;
  
  protected:
    // none yet
};

#endif
