/*
 * eepnew.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: preethibodduluri
 */
//initializing the overflow counter address to 0 and
//the counter for overflow counter address as 1 and
//appliance status address as 3 if the number of overflows exceeds the maximum
#include"testeep.h"
#include <EEPROM.h>

void EEPROMManager::EEPROMinit()
{

       number_of_overflows_counter=0;
       counterValAddr=(number_of_overflows_counter)*5+1;
       applianceaddr=(number_of_overflows_counter) *5+3;
       EEPROM.write(counterValAddr,0);
       counter=EEPROM.read(counterValAddr);
}

bool EEPROMManager::writeAppStatus()
{

	 if  (counter == maximum_writes)
	{
	  			applianceaddr=applianceaddr+5; // increase the appliance address value to the next free memory
	  			number_of_overflows_counter=number_of_overflows_counter+1;
	  			counterValAddr=number_of_overflows_counter+5;
	  			Serial.println(applianceaddr);
	  			Serial.print("\t");
	  			Serial.println(number_of_overflows_counter);
	  			counter=0;
	  			EEPROM.write(counterValAddr,0);
	  			delay(1000);
	}

     else

	 {

		EEPROM.write(applianceaddr,appStatus[0]); // appliance status is written in appropriate place
	  	EEPROM.write(applianceaddr+1,appStatus[1]);
	    counter++;
	    Serial.println(counter);
	  	delay(1000);
	 }

}
byte EEPROMManager::readAppStatus()
{
    val[0]= EEPROM.read(applianceaddr);      // finds the location of the appliance status byte and returns the value
    val[1]= EEPROM.read(applianceaddr++);
    delay(1000);
}

