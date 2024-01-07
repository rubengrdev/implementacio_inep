#include "passarelaPaquetVideojocs.h"

//Constructora
passarelaPaquetVideojocs::passarelaPaquetVideojocs(string n) {
	nom = n;
}

//Destructora
passarelaPaquetVideojocs::~passarelaPaquetVideojocs() {

}

//Getter
string passarelaPaquetVideojocs::getNom() {
	return nom;
}

//No fan falta setters ja que l'usuari no pot modificar el cataleg de la botiga.

//No fan falta operacions de inserir, modificar i esborrar ja que l'usuari no pot modificar el cataleg de la botiga.