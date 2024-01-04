#include "videoconsola.h"

Videoconsola::Videoconsola() {
	sessioIniciada = false;
}

Videoconsola& Videoconsola::getInstance() {
	static Videoconsola instance;
	return instance;
}

string Videoconsola::getUsuari(){
	return usuari;
}

void Videoconsola::iniciarSessio(string u){
	sessioIniciada = true;
	usuari = u;
}

void Videoconsola::tancarSessio(){
	sessioIniciada = false;
}