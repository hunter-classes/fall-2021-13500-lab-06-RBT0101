#include <iostream>
#include <cctype>
#include <cmath>
#include <limits>
#include <vector>
#include "solve.h"
#include "decryption.h"
#include "caesar.h"

double getDistance(int x1, int x2){
	return sqrt(abs(pow(x1,2) - pow(x2,2)));
}

std::string solve(std::string encryptedStr){
	std::string resultingStr = "";
	//English letter frequencies
	std::vector<int> englishLetterFrequency = {
		8000, 1600, 3000, 4400, 12000, 2500,
		1700, 6400, 8000, 400, 800, 4000, 3000,
		8000, 8000, 1700, 500, 6200, 8000, 9000,
		3400, 1200, 2000, 400, 2000, 200
	};
	
	double currDist = std::numeric_limits<double>::max();
	int minShift = 0;
	//Rotate encrypted_string ith number of times
	for (int i=1; i<=25; ++i){
		std::vector<int> rotatedStrFrequency(26, 0);
		std::string rotatedStr = "";
		
		//Encrypt string with ith rotation
		for (int j=0; j<encryptedStr.length(); ++j){
				rotatedStr += shiftChar(encryptedStr[j], i);
		}
		
		//Add the frequency of letter(s) into the rotatedStrFrequency vector
		for (int k=0; k<rotatedStr.length(); ++k){
			char ch = rotatedStr[k];
			if (ch >= 65 && ch <= 90){
				rotatedStrFrequency[ch-65] += 1;
			}
			else if (ch >= 97 && ch <= 122){
				rotatedStrFrequency[ch-97] += 1;
			}
		}
	
		
		std::cout << "Rotated String = " << rotatedStr << std::endl;
		double distance = 0;
		for (int l=0; l<rotatedStrFrequency.size(); ++l){
			distance += getDistance(rotatedStrFrequency[l], englishLetterFrequency[l]);
			std::cout << distance << std::endl;
		}
		
		if (distance < currDist){
			currDist = distance;
			minShift = i;
		}
	}
	
		std::cout << "smallest distance = " << currDist << std::endl;
		std::cout << "min shift = " << minShift << std::endl;
		for (int i=0; i<encryptedStr.length(); ++i ){
				resultingStr += decryptChar(encryptedStr[i], 26-minShift);
		}

		
		std::cout << resultingStr << std::endl;
		return resultingStr;
}
