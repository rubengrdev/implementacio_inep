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
	cercadoraUsuari find_us = cercadoraUsuari();
	result = false;	//per defecte fals


	try {
		cercadoraUsuari find_us = cercadoraUsuari();
		find_us.cercaPerSobrenom(sobrenom);
	}
	catch (...) {
		try {
			pus.insereix();
			result = true;
		}
		catch (...) {
			throw exception("Correu ja registrat.");
		}
		return;
	}
	throw exception("L'usuari ja existeix.");

}

bool TXregistrarUsuari::obteResultat() {
	return result;
}
