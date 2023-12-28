#include "TXtancarSessio.h"

TXtancarSessio::TXtancarSessio() {
	resultat = true;
}

TXtancarSessio::~TXtancarSessio() {

}

void TXtancarSessio::executar(){
	Videoconsola& vid = Videoconsola::getInstance();
	vid.tancarSessio();
	resultat = false;
}

bool TXtancarSessio::obteResultat(){
	return resultat;
}