compile:
	g++ -c Programa.cpp
	g++ -c Funkcijos.cpp
	g++ -o main Programa.o Funkcijos.o

compile1:
	g++ -O1 -c Programa.cpp
	g++ -O1 -c Funkcijos.cpp
	g++ -O1 -o main Programa.o Funkcijos.o

compile2:
	g++ -O2 -c Programa.cpp
	g++ -O2 -c Funkcijos.cpp
	g++ -O2 -o main Programa.o Funkcijos.o

compile3:
	g++ -O3 -c Programa.cpp
	g++ -O3 -c Funkcijos.cpp
	g++ -O3 -o main Programa.o Funkcijos.o

delete:
	del *.o *.exe 3 Vykeliai.txt Nevykeliai.txt