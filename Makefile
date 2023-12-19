CXX = g++
CXXFLAGS = -g -O0 -Wall -Wno-deprecated -std=c++20 


#main.o: implementacio.o capaDomini.o capaDades.o capaPresentacio.o
#	g++ -o main.o implementacio.o capaDomini.o capaDades.o capaPresentacio.o $(CXXFLAGS) 


#implementacio.o: inep_implementacio.cpp capaDomini.o capaDades.o capaPresentacio.o
#	g++ -o implementacio.o inep_implementacio.cpp capaDomini.o capaDades.o capaPresentacio.o $(CXXFLAGS)

main.exe: inep_implementacio.o capaDomini.o capaPresentacio.o
	g++ -o main.exe inep_implementacio.o capaDomini.o capaPresentacio.o $(CXXFLAGS)

inep_implementacio.o: inep_implementacio.cpp capaDomini.o capaPresentacio.o
	g++ -c inep_implementacio.cpp  $(CXXFLAGS)

capaDomini.o: capaDomini.cpp capaDomini.h
	g++ -c capaDomini.cpp $(CXXFLAGS)


capaPresentacio.o: capaPresentacio.cpp capaPresentacio.h
	g++ -c capaPresentacio.cpp $(CXXFLAGS)

cercadoraCompra.o: cercadoraCompra.cpp cercadoraCompra.h
	g++ -c cercadoraCompra.cpp $(CXXFLAGS)

cercadoraUsuari.o: cercadoraUsuari.cpp cercadoraUsuari.h
	g++ -c cercadoraUsuari.cpp $(CXXFLAGS)

passarelaCompra.o: passarelaCompra.cpp passarelaCompra.h
	g++ -c passarelaCompra.cpp $(CXXFLAGS)

passarelaConte.o: passarelaConte.cpp passarelaConte.h
	g++ -c passarelaConte.cpp $(CXXFLAGS)

passarelaElementCompra.o: passarelaElementCompra.cpp passarelaElementCompra.h
	g++ -c passarelaElementCompra.cpp $(CXXFLAGS)

passarelaPaquetVideojocs.o: passarelaPaquetVideojocs.cpp passarelaPaquetVideojocs.h
	g++ -c passarelaPaquetVideojocs.cpp $(CXXFLAGS)

passarelaUsuari.o: passarelaUsuari.cpp passarelaUsuari.h
	g++ -c passarelaUsuari.cpp $(CXXFLAGS)

passarelaVideojoc.o: passarelaVideojoc.cpp passarelaVideojoc.h
	g++ -c passarelaVideojoc.cpp $(CXXFLAGS)

capa.o: capaDomini.o capaPresentacio.o cercadoraCompra.o cercadoraUsuari.o passarelaCompra.o passarelaConte.o passarelaElementCompra.o passarelaPaquetVideojocs.o passarelaUsuari.o passarelaVideojoc.o
	g++ -o capaCercadorPasarela cercadoraCompra.o cercadoraUsuari.o passarelaCompra.o passarelaConte.o passarelaElementCompra.o passarelaPaquetVideojocs.o passarelaUsuari.o passarelaVideojoc.o $(CXXFLAGS)



clean:
	rm *.o
	rm *.exe
