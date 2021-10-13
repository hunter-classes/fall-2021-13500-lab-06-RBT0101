#include <iostream>
#include "decryption.h"
#include "caesar.h"
#include "vigenere.h"

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

std::string decryptCaesar(std::string plainText, int rShift){
	std::string encryptedStr = "";	
	encryptedStr += encryptCaesar(plainText, rShift);
	
	std::string decryptedStr = "";
	for (int i=0; i<encryptedStr.length(); ++i){
		decryptedStr += decryptChar(encryptedStr[i], rShift);
	}

	return decryptedStr;
}

std::string decryptVigenere(std::string plainText, std::string keyword){
	std::string encryptedStr = "";	
	encryptedStr += encryptVigenere(plainText, keyword);
	
	std::string decryptedStr = "";
	int j =0;
	char c;
	for (int i=0; i<encryptedStr.length(); ++i){
		if (j >= keyword.length()) c = keyword[0];
		else c = keyword[j];
		
		if (isalpha(encryptedStr[i])){
			decryptedStr += decryptChar(encryptedStr[i], c-97);
			j++;
		}
		else{
		decryptedStr += encryptedStr[i];
		}	
	}
	
	return decryptedStr;
}
