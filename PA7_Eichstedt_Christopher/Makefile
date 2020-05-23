all: main
main: main.cpp polynomial.o
	g++ main.cpp polynomial.o -o main
polynomial.o: polynomial.cpp polynomial.h
	g++ -c polynomial.cpp
