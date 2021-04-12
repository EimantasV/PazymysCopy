compile:
	g++ -c Programa.cpp
	g++ -c Funkcijos.cpp
	g++ -o main Programa.o Funkcijos.o

compile3:
	g++ -O3 -std=c++17 -c Programa.cpp
	g++ -O3 -std=c++17 -c Funkcijos.cpp
	g++ -O3 -std=c++17 -o main Programa.o Funkcijos.o

delete:
	del *.o *.exe 3 Vykeliai.txt Nevykeliai.txt