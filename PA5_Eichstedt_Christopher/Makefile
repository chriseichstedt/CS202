all: a.out main
a.out: test.cpp String.o
	g++ test.cpp String.o -o a.out
main: main.cpp String.o
	g++ main.cpp String.o -o main
String.o: String.cpp String.h
	g++ -c String.cpp
