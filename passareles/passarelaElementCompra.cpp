#include "passarelaElementCompra.h"

//Constructora
passarelaElementCompra::passarelaElementCompra(string n, string desc, double p, string t) {
	nom = n;
	descripcio = desc;
	preu = p;
	tipus = t;
}

//Destructora
passarelaElementCompra::~passarelaElementCompra() {

}

//Getters
string passarelaElementCompra::getNom() {
	return nom;
}

string passarelaElementCompra::getDescripcio() {
	return descripcio;
}

double passarelaElementCompra::getPreu() {
	return preu;
}

string passarelaElementCompra::getTipus() {
	return tipus;
}

//No fan falta setters ja que l'usuari no pot modificar el cataleg de la botiga.

//No fan falta operacions de inserir, modificar i esborrar ja que l'usuari no pot modificar el cataleg de la botiga.