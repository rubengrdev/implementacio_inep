#include "passarelaVideojoc.h"

//Constructora
passarelaVideojoc::passarelaVideojoc(string n, int q, string data, string g, int mins) {
	nom = n;
	qualificacio = q;
	dataLlan = data;
	genere = g;
	minsEstimat = mins;
}

//Destructora
passarelaVideojoc::~passarelaVideojoc() {

}

//Getters
string passarelaVideojoc::getNom() {
	return nom;
}

string passarelaVideojoc::getDataLlan() {
	return dataLlan;
}

string passarelaVideojoc::getGenere() {
	return genere;
}

int passarelaVideojoc::getQualificacio() {
	return qualificacio;
}

int passarelaVideojoc::getMinsEstimat() {
	return minsEstimat;
}

//No fan falta setters ja que l'usuari no pot modificar el cataleg de la botiga.

//No fa falta cap operacio amb la base de dades ja que l'usuari no pot modificar el catalega de la botiga.