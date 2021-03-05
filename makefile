compile:
	g++ -c Vectors.cpp
	g++ -c Funkcijos.cpp
	g++ -o main Vectors.o Funkcijos.o
delete:
	del *.o *.exe