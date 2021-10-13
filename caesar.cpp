#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rShift){
	int chShifted = c + rShift;
	
	char resultingChar = chShifted;
	if (c >= 65 && c <= 90){
		if (chShifted > 90) resultingChar = 65 + ((chShifted%91)%26);	//%90 represents "remainder" from max code point and %26 represents remainder from alphabetical cycle
		
	}
	else if (c >= 97 && c <= 122){
		if (chShifted > 122) resultingChar = 97 + ((chShifted%123)%26);	//same as above scenario.
	}
	else{
		resultingChar = c;
	}
	
	return resultingChar;
}

std::string encryptCaesar(std::string plainText, int rShift){
	std::string shiftedStr = "";
	for (int i=0; i<plainText.length(); ++i){
		shiftedStr += shiftChar(plainText[i], rShift);
	}
	
	return shiftedStr;
}
