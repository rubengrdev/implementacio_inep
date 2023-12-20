CXX = g++
CXXFLAGS = -g -O0 -Wall -Wno-deprecated -std=c++20 


#main.o: implementacio.o capaDomini.o capaDades.o capaPresentacio.o
#	g++ -o main.o implementacio.o capaDomini.o capaDades.o capaPresentacio.o $(CXXFLAGS) 


#implementacio.o: inep_implementacio.cpp capaDomini.o capaDades.o capaPresentacio.o
#	g++ -o implementacio.o inep_implementacio.cpp capaDomini.o capaDades.o capaPresentacio.o $(CXXFLAGS)


inep_implementacio.o: inep_implementacio.cpp capaPresentacio.o
	g++ -c inep_implementacio.cpp  $(CXXFLAGS)

capaPresentacio.o: capaPresentacio.cpp capaPresentacio.h
	g++ -c capaPresentacio.cpp $(CXXFLAGS)

main.exe: inep_implementacio.o capaDomini.o capaDades.o capaPresentacio.o
	g++ -o main.exe inep_implementacio.o capaDomini.o capaDades.o capaPresentacio.o $(CXXFLAGS)

clean:
	rm *.o
	rm *.exe
