#include "TXesborrarUsuari.h"

TXesborrarUsuari::TXesborrarUsuari(string c) {
	contrasenya = c;
	result = true;
}

TXesborrarUsuari::~TXesborrarUsuari() {

}

void TXesborrarUsuari::executar() {
	Videoconsola& vid = Videoconsola::getInstance();
	string sn = vid.getUsuari();
	cercadoraUsuari us = cercadoraUsuari();
	passarelaUsuari pus = us.cercaPerSobrenom(sn);
	if (pus.getContrasenya() == contrasenya) {
		pus.esborra();
		result = false;
		vid.tancarSessio();
	}
	else {
		throw exception("Contrasenya incorrecta");
	}
}

bool TXesborrarUsuari::obteResultat() {
	return result;
}