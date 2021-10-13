#include <iostream>

void testAscii(std::string input){
	std::string inputText = input;
	
	for (int i=0; i<inputText.length(); ++i){
		std::cout << inputText[i] << " " << (int) inputText[i] << std::endl;
	}
}
