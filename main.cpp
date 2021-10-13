#include <iostream>
#include "test_ascii.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"

int main()
{
  //Task A
  testAscii("meals");
  std::cout << "\n";
  
  testAscii(": ; ! ? < > ~");
  std::cout << "\n";
  
  testAscii("        ");
  std::cout << "\n";
  
  testAscii("");
  std::cout << "\n";
  
  std::cout << "TASK B\n";
  //Task B
  std::cout << encryptCaesar("Way to Go!", 5);
  std::cout << "\n";
  
  std::cout << encryptCaesar("XY", 2);
  std::cout << "\n";
  
  std::cout << encryptCaesar("..?>>>>", 50);
  std::cout << "\n";
  
  std::cout << encryptCaesar("Z", 5000);
  std::cout << "\n";
  
  std::cout << encryptCaesar("", 20);
  std::cout << "\n";
  
  std::cout << "TASK C\n";
  //Task C
  std::cout << encryptVigenere("Hello", "cake");
  std::cout << "\n";
  
  std::cout << encryptVigenere("a", "cake");
  std::cout << "\n";
  
  std::cout << encryptVigenere("boat", "row");
  std::cout << "\n\n";
  
  std::cout << "TASK D\n";
  //Task D
  std::cout << decryptCaesar("Way to Go!", 5);
  std::cout << "\n\n";
  
  std::cout << decryptVigenere("Hello", "cake");
  std::cout << "\n\n";
  
  std::cout << decryptVigenere("boat", "row");
  std::cout << "\n\n";
  return 0;
}
