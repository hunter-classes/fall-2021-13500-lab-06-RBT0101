#include <iostream>
#include "solve.h"
#include "decryption.h"
#include "caesar.h"

//Note to self: If "solve.h" uses methods from other files, then these files must be included in main
int main(){
	//std::string decryptedStr = "";
	
	//eppn
	std::string str1 = encryptCaesar("doom", 1);
	//std::cout << str1 << std::endl;
	
	//for (int i=0; i<str1.length(); i++){
	//	decryptedStr += decryptChar(str1[i], 1);
	//}
	//std::cout << decryptedStr << std::endl;
	
	solve(str1);
	return 0;
}
