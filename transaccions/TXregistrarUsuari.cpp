#include "TXregistrarUsuari.h"

TXregistrarUsuari::TXregistrarUsuari(string n, string sn, string c, string correu, string data) {
	nom = n;
	sobrenom = sn;
	constrasenya = c;
	correuE = correu;
	dataN = data;
}

TXregistrarUsuari::~TXregistrarUsuari() {

}


void TXregistrarUsuari::executar(){
	//crida al constructor per defecte
	//TO DO... comprovació d'errors, dades correctes?
	passarelaUsuari pus(nom, sobrenom, constrasenya, correuE, dataN);
	pus.insereix();	//insereix encara no funciona
}

bool TXregistrarUsuari::obteResultat() {
	bool result = false;	//to do...
	return result;
}
