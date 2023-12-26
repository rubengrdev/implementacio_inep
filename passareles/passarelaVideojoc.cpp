#include "passarelaVideojoc.h"

passarelaVideojoc::passarelaVideojoc(string n, int q, string data, string g, int mins) {
	nom = n;
	qualificacio = q;
	dataLlan = data;
	genere = g;
	minsEstimat = mins;
}

passarelaVideojoc::~passarelaVideojoc() {

}

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