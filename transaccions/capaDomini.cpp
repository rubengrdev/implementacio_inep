#include "capaDomini.h"

capaDomini::capaDomini() {

}

capaDomini::~capaDomini() {

}
<<<<<<< HEAD
//aixó segons el diagrama de classes no hauria d'estar aquí, hauria de ser a la transacció TXIniciarSessio, TO DO...
/*
void capaDomini::iniciarSessio(string nom, string contrasenya){
	cercadoraUsuari usuari(nom);
	usuari.cercaUsuari();
	//cout << "He accedit a la capa domini!" << endl;
}
*/
=======
>>>>>>> 2354cd233d55582b222f9a67a4ba556e093b764f

void capaDomini::registrarUsuari(string nom, string sobrenom, string contrasenya, string correuE, string dataN) {
	passarelaUsuari usuari(nom, sobrenom, contrasenya, correuE, dataN);
	usuari.insereix();
}
/*
pqxx::result capaDomini::totsVideojocs() {
	//cercadoraVideojocs videojoc();
	//return videojoc.totsVideojocs
	return pqxx::result result();
}
*/