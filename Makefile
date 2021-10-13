main: main.o test_ascii.o caesar.o vigenere.o decryption.o;
	g++ -o main main.o test_ascii.o caesar.o vigenere.o decryption.o

tests: tests.o test_ascii.o caesar.o vigenere.o decryption.o;
	g++ -o tests tests.o test_ascii.o caesar.o vigenere.o decryption.o

decryption.o: decryption.cpp decryption.h
	g++ -c decryption.cpp
	
vigenere.o:  vigenere.cpp vigenere.h 
	g++ -c vigenere.cpp 
	
caesar.o: caesar.cpp caesar.h
	g++ -c caesar.cpp
	
test_ascii.o: test_ascii.cpp test_ascii.h
	g++ -c test_ascii.cpp 
	
main.o: main.cpp test_ascii.h caesar.h
	g++ -c main.cpp
	
tests.o: tests.cpp doctest.h
	g++ -std=c++11 -c tests.cpp 
	
clean:
	rm -f main tests main.o tests.o test_ascii.o caesar.o vigenere.o decryption.o
