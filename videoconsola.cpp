#include "videoconsola.h"

Videoconsola& Videoconsola::getInstance() {
	static Videoconsola instance;
	return instance;
}

//Getter
passarelaUsuari* Videoconsola::getUsuari(){
	return usuari;
}

//Setters
void Videoconsola::iniciarSessio(passarelaUsuari *ppus){
	usuari = ppus;
}

void Videoconsola::tancarSessio(){
	usuari = NULL;
}