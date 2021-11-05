#include <iostream>
#include "decryption.h"

char decryptChar(char c, int rShift){
	int chShifted = c - rShift;
	
	char resultingChar = chShifted;
	if (c >= 65 && c <= 90){
		if (chShifted < 65) resultingChar =  90 - ((64%chShifted)%26);	//reverse as caesar cipher encoding
		
	}
	else if (c >= 97 && c <= 122){
		if (chShifted < 97) resultingChar = 122 - ((96%chShifted)%26);	//same as above scenario.
	}
	else{
		resultingChar = c;
	}
	
	return resultingChar;
}


