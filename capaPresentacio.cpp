#include "capaPresentacio.h"

capaPresentacio::capaPresentacio() {
	cDom = capaDomini();
<<<<<<< HEAD
	txIniSessio = TXIniciarSessio();

=======
>>>>>>> 2354cd233d55582b222f9a67a4ba556e093b764f
}

capaPresentacio::~capaPresentacio() {

}

void capaPresentacio::iniciarSessioPres() {
	cin.ignore();
	system("CLS");
	string s, c;
	cout << "** Inici sessio **" << endl;
	cout << "Sobrenom: ";
	getline(cin, s);
	cout << "Contrasenya: ";
	getline(cin, c);
	//Crida a cDom
<<<<<<< HEAD
	txIniSessio.iniciarSessio(s, c);
	//Tractament errors
	cout << "Sessio iniciada correctament!" << endl;

=======
	//Tractament errors
	cout << "Sessio iniciada correctament!" << endl;
>>>>>>> 2354cd233d55582b222f9a67a4ba556e093b764f
}

void capaPresentacio::tancarSessioPres() {
	cin.ignore();
	system("CLS");
	string op;
	cout << "** Tancar sessio **" << endl;
	cout << "Vols tancar la sessio (S/N): ";
	cin >> op;
	if (op == "S") {
		//crida a cDom
		cout << "Sessio tancada correctament!" << endl;
	}
	else if (op == "N") {
		return;
	}
	else {
		cout << "Has de contestar amb S o N!" << endl;
	}
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
	cin.ignore();
	system("CLS");
	cout << "** Consulta usuari **" << endl;
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::modificarUsuariPres() {
	cin.ignore();
	system("CLS");
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::esborrarUsuariPres() {
	cin.ignore();
	system("CLS");
	string c;
	cout << "** Esborrar usuari **" << endl;
	cout << "Introdueix la teva contrasenya per confirmar l'esborrat: ";
	cin >> c;
	//crida a cDom
	//Tractament d'errors
	cout << "Usuari esborrat correctament!" << endl;
}

void capaPresentacio::comprarVideojocPres() {
	cin.ignore();
	system("CLS");
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::comprarPaquetPres() {
	cin.ignore();
	system("CLS");
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::consultarCompresPres() {
	cin.ignore();
	system("CLS");
	cout << "WORK IN PROGRESS" << endl;
}

void capaPresentacio::consultarVideojocPres() {
	cin.ignore();
	system("CLS");
	string s;
	cout << "** Consulta videojoc **" << endl;
	cout << "Introdueix el nom del videojoc a consultar : ";
	getline(cin, s);
	//Crida a cDom
	//Tractament errors
<<<<<<< HEAD
	cout << "Informaci� sobre el videojoc..." << endl;
	//Mostrar resposta de cDom
}

/*TO DO... revisar pqxx::result dona error*/
=======
	cout << "Informaci� sobre el videojoc..." << endl;
	//Mostrar resposta de cDom
}

>>>>>>> 2354cd233d55582b222f9a67a4ba556e093b764f
void capaPresentacio::consultarVideojocsPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta tots els videojocs **" << endl;
	//Crida a cDom
	/*
	pqxx::result result = cDom.totsVideojocs();
	for (size_t i = 0; i < result.size(); ++i) {
		for (size_t j = 0; j < result[i].size(); ++j) {
			cout << result[i][j].name() << ": " << result[i][j].c_str() << "\t";
		}
		cout << endl;
	}
	//Mostrar resposta de cDom
	*/
}
void capaPresentacio::consultarVideojocsEdatPres() {
	cin.ignore();
	system("CLS");
	int edat = 0;	//to do, asignar valor a edat per warning al vstudio
	cout << "** Consulta videojocs per edat **" << endl;
	cout << "Edat maxima (anys): ";
	//Crida
	//Mostrar resultat
}

void capaPresentacio::consultarNovetatsPres() {
	cin.ignore();
	system("CLS");
	string data;
	cout << "** Consulta novetats **" << endl;
	cout << "Data (DD/MM/AAAA): ";
	getline(cin, data);
	//Crida
	//Mostrar resultat
}

void capaPresentacio::consultarPaquetPres() {
	cin.ignore();
	system("CLS");
	string nPaquet;
	cout << "** Consulta paquet **" << endl;
	cout << "Nom paquet: ";
	getline(cin, nPaquet);
	//Crida
	//Tractament errors
	//Mostrar resultat
}

void capaPresentacio::consultarPaquetsPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta paquets **" << endl;
	//Crida
	//Mostrar resultat
}