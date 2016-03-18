/*
 * eepnew.h
 *
 *  Created on: Aug 14, 2015
 *      Author: preethibodduluri
 */

#ifndef EEPNEW_H_
#define EEPNEW_H_
#define maximum_writes 20
#define initial 0
#include"Arduino.h"


class EEPROMManager
{
private:


public:
      void EEPROMinit();

                byte val[];
     	        byte appStatus[];
     	        int  applianceaddr;
     		    int  number_of_overflows_counter;
     		 	int  counterValAddr;
     		    int  readval;
     		    int  counter;
                int  x;
	/*
	 * This method writes the appliance status byte to the EEPROM
	 * @params: appStatus is the status byte which signifies the 4 appliance's status.
	 * @return: returns if the byte is succesfully written or not
	 */
	bool writeAppStatus();// you have to read the value at the overflow counters
	// and write the appliance status at the appropriate place.
	/*
	 * @return: This method reads the value of the overflow counter and based on that
	 * finds the location of the appliance status byte and returns the value of that
	 * position.
	 */

	 byte readAppStatus ();

};

extern EEPROMManager testeep;

#endif /* EEPNEW_H_ */

