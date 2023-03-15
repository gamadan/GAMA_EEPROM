#include "GAMA_EEPROM.h"

GAMA_EEPROM eeprom = GAMA_EEPROM();

void setup() {
  Serial.begin(115200);
  while(!Serial) {} 

  eeprom.begin();

  std::string channel = eeprom.initChannelValues();
  std::string password = eeprom.initPassword();
  Serial.print("Channel: ");Serial.println(channel.c_str());
  Serial.print("Password: ");Serial.println(password.c_str());

}

void loop() {
  vTaskDelete(NULL);
}