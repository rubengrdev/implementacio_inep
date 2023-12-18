#include "passarelaUsuari.h"

passarelaUsuari::passarelaUsuari(string n, string sn, string c, string cE, string dN) {
	nom = n;
	sobrenom = sn;
	contrasenya = c;
	correuE = cE;
	dataN = dN;
}

passarelaUsuari::~passarelaUsuari() {

}

string passarelaUsuari::getNom() {
	return nom;
}

string passarelaUsuari::getSobrenom() {
	return sobrenom;
}

string passarelaUsuari::getContrasenya() {
	return contrasenya;
}

string passarelaUsuari::getCorreu() {
	return correuE;
}

string passarelaUsuari::getDataN() {
	return dataN;
}

void passarelaUsuari::setNom(string n) {
	nom = n;
}

void passarelaUsuari::setSobrenom(string sn) { //No faria falta pq no es pot modificar el id (?)
	sobrenom = sn;
}

void passarelaUsuari::setContrasenya(string c) {
	contrasenya = c;
}

void passarelaUsuari::setCorreu(string cE) {
	correuE = cE;
}

void passarelaUsuari::setDataN(string dN) {
	dataN = dN;
}