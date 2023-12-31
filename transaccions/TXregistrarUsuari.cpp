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
	int diff = strcmp(find_us.cercaPerSobrenom(sobrenom).getSobrenom().c_str(), sobrenom.c_str());
	//si hi ha diferencies entre el sobrenom donat i trobat, el sobrenom és lliure
	try {
		if (diff != 0) {
			pus.insereix();
		}
	}
	catch (exception& e) {
	
	}

	/*
	if (strcmp(find_us.cercaPerSobrenom(sobrenom).getSobrenom().c_str(), sobrenom.c_str()) != 0) {
		//pus.insereix();
	}
	else {
		throw exception("Sobrenom ja en us");
	}
	*/
	

	
}

bool TXregistrarUsuari::obteResultat() {
	bool result = false;	//to do...
	return result;
}
