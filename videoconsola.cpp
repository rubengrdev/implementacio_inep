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
void Videoconsola::iniciarSessio(passarelaUsuari *pus2){
	sessioIniciada = true;
	pus = pus2;
}

void Videoconsola::tancarSessio(){
	sessioIniciada = false;
}