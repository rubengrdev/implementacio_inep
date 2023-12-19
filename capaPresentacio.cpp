#include "capaPresentacio.h"

capaPresentacio::capaPresentacio() {
	cDom = capaDomini();
}

capaPresentacio::~capaPresentacio() {

}

void capaPresentacio::iniciarSessioPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::registrarUsuariPres() {
	cin.ignore();
	system("CLS");
	string nom, sobrenom, contrasenya, correuE, dataN;
	cout << "----- CREACIO D'UN NOU USUARI -----" << endl;
	cout << "Nom (complet): ";
	getline(cin, nom);
	cout << "Sobrenom: ";
	getline(cin, sobrenom);
	cout << "Contrasenya: ";
	getline(cin, contrasenya);
	cout << "Correu electronic: ";
	getline(cin, correuE);
	cout << "Data de naixement (DD/MM/AAAA): ";
	getline(cin, dataN);
	cDom.registrarUsuari(nom, sobrenom, contrasenya, correuE, dataN);
	//Tractament d'errors
	cout << "Usuari registrat correctament!" << endl;
}

void capaPresentacio::consultarUsuariPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::modificarUsuariPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::esborrarUsuariPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::comprarVideojocPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::comprarPaquetPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::consultarCompresPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::consultarVideojocPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::consultarVideojocsPres() { //mirar si vol dir que es paquet
	cout << "WORK IN PROGRESS" << endl;
}
void capaPresentacio::consultarVideojocsEdatPres() {
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::consultarNovetatsPres() {
	cout << "WORK IN PROGRESS" << endl;
}