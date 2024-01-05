#include "videoconsola.h"

//Constructora privada
Videoconsola::Videoconsola() {
	sessioIniciada = false;
}

//Operacio per rebre la instancia de videoconsola 
Videoconsola& Videoconsola::getInstance() {
	static Videoconsola instance;
	return instance;
}

//Getter
string Videoconsola::getUsuari(){
	return usuari;
}

//Setters
void Videoconsola::iniciarSessio(string u){
	sessioIniciada = true;
	usuari = u;
}

void Videoconsola::tancarSessio(){
	sessioIniciada = false;
}