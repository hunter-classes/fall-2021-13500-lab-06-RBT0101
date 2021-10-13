#include <iostream>
#include "vigenere.h"

char shiftCharVigenere(char c, int rShift){
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

std::string encryptVigenere(std::string plainText, std::string keyword){
	std::string resultingStr = "";
	char firstLetter = keyword[0];
	
	char c;
	int j = 0;
	for (int i=0; i<plainText.length(); ++i){
		if (j >= keyword.length()) c = keyword[0];
		else c = keyword[j];
		
		if (isalpha(plainText[i]) != 0){
			resultingStr += shiftCharVigenere((int)plainText[i], (int)c-97);
			j++;
		}
		else{
			resultingStr += plainText[i];
		}
	}
	
	return resultingStr;
}
