#include "TXiniciarSessio.h"

TXiniciarSessio::TXiniciarSessio(string sn, string cs) {
	sobrenom = sn;
	contrasenya = cs;
	resultat = false;
}

TXiniciarSessio::~TXiniciarSessio() {

}

void TXiniciarSessio::executar(){
	cercadoraUsuari us = cercadoraUsuari();
	passarelaUsuari pus = us.cercaPerSobrenom(sobrenom);
	if(pus.getContrasenya() == contrasenya){
		resultat = true;
		Videoconsola& vid = Videoconsola::getInstance();
		vid.iniciarSessio(&pus);
	}else{
		throw exception("Usuari o contrasenya incorrecta");
	}
}

bool TXiniciarSessio::obteResultat(){
	return resultat;
}