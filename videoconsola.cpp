#include "videoconsola.h"
#include "cercadors/cercadoraUsuari.h"
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
	return pus->getSobrenom();
}

//Setters
void Videoconsola::iniciarSessio(passarelaUsuari pus2){
	sessioIniciada = true;
	cercadoraUsuari us = cercadoraUsuari();
	*pus = pus2;
	
	//usuari = pus->getSobrenom();
}

void Videoconsola::tancarSessio(){
	sessioIniciada = false;
}