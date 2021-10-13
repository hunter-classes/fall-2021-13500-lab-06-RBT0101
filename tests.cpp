#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "test_ascii.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"

// add your tests here
//Task B
TEST_CASE("Checking caesar.cpp"){
	CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
	CHECK(encryptCaesar("XY", 2) == "ZA");
	CHECK(encryptCaesar("..?>>>>", 50) == "..?>>>>");
	CHECK(encryptCaesar("Z", 5000) == "H");
	CHECK(encryptCaesar("", 20) == "");
}

//Task C
TEST_CASE("Checking vigenere.cpp"){
	CHECK(encryptVigenere("Hello", "cake") == "Jevpq");
	CHECK(encryptVigenere("c", "cake") == "e");
	CHECK(encryptVigenere("boat", "row") == "scwk");
}

//Task D
TEST_CASE("Checking decryption.cpp"){
	CHECK(decryptCaesar("Way to Go!", 5) == "Way to Go!");
	CHECK(decryptVigenere("Hello", "cake") == "Hello");
	CHECK(decryptVigenere("boat", "row") == "boat");
}


