main: main.o solve.o decryption.o caesar.o
	g++ -o main main.o solve.o decryption.o caesar.o

tests: tests.o caesar.o decryption.o solve.o
	g++ -o tests tests.o caesar.o decryption.o

decryption.o: decryption.cpp decryption.h
	g++ -c decryption.cpp
	
caesar.o: caesar.cpp caesar.h
	g++ -c caesar.cpp
	
solve.o: solve.cpp solve.h caesar.h decryption.h
	g++ -std=c++11 -c solve.cpp

main.o: main.cpp caesar.h
	g++ -c main.cpp
	
tests.o: tests.cpp doctest.h solve.h
	g++ -std=c++11 -c tests.cpp 
	
clean:
	rm -f main tests main.o tests.o caesar.o decryption.o solve.o;
