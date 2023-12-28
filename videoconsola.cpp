#include "videoconsola.h"

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