all: KMP

KMP: main.o prefix.o KMP.o
	g++ main.o prefix.o KMP.o
	
main.o: main.cpp prefix.cpp KMP.cpp prefix.h KMP.h
	g++ -c main.cpp

prefix.o: prefix.h prefix.cpp
	g++ -c prefix.cpp

KMP.o: prefix.h prefix.cpp KMP.h KMP.cpp
	g++ -c KMP.cpp

clean:
	rm -rf .o KMP