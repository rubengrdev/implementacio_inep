#include "videoconsola.h"
#include "cercadors/cercadoraUsuari.h"
//Constructora privada
Videoconsola::Videoconsola() {
	sessioIniciada = false;
	usuari = NULL;
}

//Operacio per rebre la instancia de videoconsola 
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
	sessioIniciada = true;
	usuari = ppus;
}

void Videoconsola::tancarSessio(){
	sessioIniciada = false;
	usuari = NULL;
}