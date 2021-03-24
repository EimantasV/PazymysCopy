compile:
	g++ -c Vectors.cpp
	g++ -c Funkcijos.cpp
	g++ -o main Vectors.o Funkcijos.o

compile3:
	g++ -o3 -c Vectors.cpp
	g++ -o3 -c Funkcijos.cpp
	g++ -o3 -o main Vectors.o Funkcijos.o

delete:
	del *.o *.exe 3 Vykeliai.txt Nevykeliai.txt