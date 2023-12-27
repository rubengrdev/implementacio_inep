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
	passarelaUsuari pus = us.cercaPerNom(sobrenom);
	if(pus.getContrasenya() == contrasenya){
		resultat = true;
		//Comunicacio amb Videoconsola
	}else{
		throw ("Contrasenya incorrecta");
	}
	
}

bool TXiniciarSessio::resultat(){
	return resultat;
}