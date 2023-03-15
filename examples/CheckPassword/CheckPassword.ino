#include "GAMA_EEPROM.h"

GAMA_EEPROM eeprom = GAMA_EEPROM();

void setup() {
  Serial.begin(115200);
  while(!Serial) {} 

  eeprom.begin();

  std::string channel = eeprom.initChannelValues();
  std::string password = "opensaysme";

  if(eeprom.isValidPassword(password)) Serial.println("Good password!");
  else Serial.println("Bad password!");

  password = "default";

  if(eeprom.isValidPassword(password)) Serial.println("Good password!");
  else Serial.println("Bad password!");
}

void loop() {
  vTaskDelete(NULL);
}