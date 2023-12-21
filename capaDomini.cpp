#include "capaDomini.h"

capaDomini::capaDomini() {

}

capaDomini::~capaDomini() {

}

void capaDomini::registrarUsuari(string nom, string sobrenom, string contrasenya, string correuE, string dataN) {
	passarelaUsuari usuari(nom, sobrenom, contrasenya, correuE, dataN);
	usuari.insereix();
}

pqxx::result capaDomini::totsVideojocs() {
	//cercadoraVideojocs videojoc();
	//return videojoc.totsVideojocs
	return pqxx::result result();
}