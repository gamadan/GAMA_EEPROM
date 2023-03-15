/*
 * GAMA_EEPROM.cpp
 *
 * Created: 5/1/2021 11:49:09 AM
 *  Author: dpneb
 */ 

#include "GAMA_EEPROM.h"

GAMA_EEPROM::GAMA_EEPROM() {
  size = EEPROM_SIZE;  
}
void GAMA_EEPROM::begin() {
  EEPROM.begin(size);
}

std::string GAMA_EEPROM::initChannelValues() {
  if(!hasChannelValues()) {
    saveChannelValues(CHANNEL_DEFAULT_VALUES);
  }
  return loadChannelValues();
}

void GAMA_EEPROM::saveChannelValues(std::string v) {
  EEPROM.write(CHANNEL_START_ADDRESS+0, v.at(0));
  EEPROM.write(CHANNEL_START_ADDRESS+1, v.at(1));
  EEPROM.write(CHANNEL_START_ADDRESS+2, v.at(2));
  EEPROM.write(CHANNEL_START_ADDRESS+3, v.at(3));
  EEPROM.commit();
}

std::string GAMA_EEPROM::loadChannelValues() {
  std::string output = "";
  for(int i = 0; i < CHANNEL_LENGTH; i++) {
    output.append(1, (char)EEPROM.read(CHANNEL_START_ADDRESS + i));
  }
  //Serial.print("Loaded Channel Value: ");//Serial.println(output);
  return output;
}

bool GAMA_EEPROM::hasChannelValues() {
  for(uint8_t i = 0; i < CHANNEL_LENGTH; i++) {
    if(EEPROM.read(CHANNEL_START_ADDRESS + i) == 0xFF) return false;
  }
  return true;
}


std::string GAMA_EEPROM::initPassword() {
  if(hasEmptyPassword()) {
    savePassword(PASSWORD_DEFAULT_VALUES);
  }
  return loadPassword();
}


bool GAMA_EEPROM::isValidPassword(std::string pw) {
  if(pw.compare(loadPassword()) == 0) return true;
  return false;
}

void GAMA_EEPROM::savePassword(std::string pw) {
  int password_length = pw.size();
  EEPROM.write(PASSWORD_LENGTH_ADDRESS, password_length);
  for(int i = 0; i < password_length; i++) {
    EEPROM.write(PASSWORD_ADDRESS_START + i, pw.at(i));
  }
  EEPROM.commit();
  for(int i = password_length; i < PASSWORD_MAX_CHARACTERS; i++) {
    EEPROM.write(PASSWORD_ADDRESS_START + i, 0xFF);
  }
  EEPROM.commit();
  GAMA_EEPROM::savePasswordLength(password_length);
}




std::string GAMA_EEPROM::loadPassword() {
  std::string output = "";
  int length = EEPROM.read(PASSWORD_LENGTH_ADDRESS);
  for(int i = 0; i < length; i++) {
    output.append(1, (char)EEPROM.read(PASSWORD_ADDRESS_START + i));
  }
  return output;
}





bool GAMA_EEPROM::hasEmptyPassword() {
  for(int i = 0; i < PASSWORD_MAX_CHARACTERS; i++) {
    if(EEPROM.read(i) != 255) {
      return false;
    }
  }
  return true;
}

void GAMA_EEPROM::savePasswordLength(uint8_t l) {
  EEPROM.write(PASSWORD_LENGTH_ADDRESS, l);
  EEPROM.commit();
}



uint8_t GAMA_EEPROM::getDataPin() {
  return EEPROM.read(DATA_PIN_ADDRESS);
}
uint8_t GAMA_EEPROM::getSelectorPin() {
  return EEPROM.read(SELECTOR_PIN_ADDRESS);  
}

uint8_t GAMA_EEPROM::getRSSIInputPin() {
  return EEPROM.read(RSSI_INPUT_PIN_ADDRESS);  
}


void GAMA_EEPROM::setDataPin(uint8_t p) {
  EEPROM.write(DATA_PIN_ADDRESS, p);
  EEPROM.commit();
}
void GAMA_EEPROM::setSelectorPin(uint8_t p) {
  EEPROM.write(SELECTOR_PIN_ADDRESS, p);
  EEPROM.commit();
}
void GAMA_EEPROM::setRSSIInputPin(uint8_t p) {
  EEPROM.write(RSSI_INPUT_PIN_ADDRESS, p);
  EEPROM.commit();
}
