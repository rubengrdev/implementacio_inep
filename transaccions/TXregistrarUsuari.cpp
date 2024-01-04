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
	passarelaUsuari pus(nom, sobrenom, constrasenya, correuE, dataN);
	try {
		cercadoraUsuari find_us = cercadoraUsuari();
		find_us.cercaPerSobrenom(sobrenom);
	}
	catch (...) {
		try {
			pus.insereix();
		}
		catch (...) {
			throw exception("Correu ja registrat.");
		}
		return;
	}
	throw exception("L'usuari ja existeix.");
}

