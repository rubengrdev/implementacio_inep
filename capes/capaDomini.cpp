#include "capaDomini.h"

capaDomini::capaDomini() {

}

capaDomini::~capaDomini() {

}

void capaDomini::registrarUsuari(string nom, string sobrenom, string contrasenya, string correuE, string dataN) {
	passarelaUsuari usuari(nom, sobrenom, contrasenya, correuE, dataN);
	usuari.insereix();
}
<<<<<<< HEAD:capes/capaDomini.cpp
/*
pqxx::result capaDomini::totsVideojocs() {
	//cercadoraVideojocs videojoc();
	//return videojoc.totsVideojocs
	//return pqxx::result result();
}
*/
=======

pqxx::result capaDomini::totsVideojocs() {
	//cercadoraVideojocs videojoc();
	//return videojoc.totsVideojocs
	return pqxx::result result();
}
>>>>>>> 5a95daf21fd6fbbd077a1b75075f8bc767c02a5d:capaDomini.cpp
