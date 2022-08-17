#include "GAMA_EEPROM.h"

GAMA_EEPROM eeprom = GAMA_EEPROM(512);

void setup() {
  Serial.begin(250000);
  while(!Serial) {}
  Serial.println("");
  Serial.println("");

  eeprom.begin();

  String channel = eeprom.initChannelValues();
  String password = eeprom.initPassword();
  Serial.print("Channel: ");Serial.println(channel);
  Serial.print("Password: ");Serial.println(password);
  //if(channel.equals(

}

void loop() {
  // put your main code here, to run repeatedly:

}
