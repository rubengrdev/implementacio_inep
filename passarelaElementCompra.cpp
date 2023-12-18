#include "passarelaElementCompra.h"

passarelaElementCompra::passarelaElementCompra(string n, string desc, double p, string t) {
	nom = n;
	descripcio = desc;
	preu = p;
	tipus = t;
}

passarelaElementCompra::~passarelaElementCompra() {

}

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

void passarelaElementCompra::setDescripcio(string desc) {
	descripcio = desc;
}

void passarelaElementCompra::setPreu(double p) {
	preu = p;
}