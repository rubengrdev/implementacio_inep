#include "capaPresentacio.h"

capaPresentacio::capaPresentacio() {

}

capaPresentacio::~capaPresentacio() {

}

bool capaPresentacio::iniciarSessioPres() {
	cin.ignore();
	system("CLS");
	string s, c;
	cout << "** Inici sessio **" << endl;
	cout << "Sobrenom: ";
	getline(cin, s);
	cout << "Contrasenya: ";
	getline(cin, c);
	TXiniciarSessio op = TXiniciarSessio(s, c);
	try{
		op.executar();
	}
	catch(const exception& e){
		cout << "Usuari o contrasenya incorrecta" << endl;
	}
	if (op.obteResultat()) cout << "Sessio iniciada correctament!" << endl;
	return op.obteResultat();
}

bool capaPresentacio::tancarSessioPres() {
	cin.ignore();
	system("CLS");
	string op;
	cout << "** Tancar sessio **" << endl;
	cout << "Vols tancar la sessio (S/N): ";
	cin >> op;
	TXtancarSessio ts = TXtancarSessio();
	if (op == "S") {
		ts.executar();
		cout << "Sessio tancada correctament!" << endl;
	}
	else if (op == "N") {
		return true;
	}
	else {
		cout << "Has de contestar amb S o N!" << endl;
	}
	return ts.obteResultat();
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
	TXregistrarUsuari op = TXregistrarUsuari(nom, sobrenom, contrasenya, correuE, dataN);
	op.executar();
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
	TXconsultarVideojoc op = TXconsultarVideojoc(s);
	try {
		op.executar();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
		return;
	}
	cout << "Informacio sobre el videojoc..." << endl;
	TXconsultarVideojoc::res r = op.obteResultat();
	cout << "Nom videojoc: " << r.nom << endl;
	cout << "Descripcio: " << r.desc << endl;
	cout << "Qualificacio edat: " << r.qualificacio << endl;
	cout << "Genere: " << r.genere << endl;
	cout << "Data llancament: " << r.data << endl;
	cout << "Preu: " << r.preu << " euros" << endl;
	cout << "Paquets on esta inclos: ";
	for (int i = 0; i < r.paquets.size(); i++) {
		if (i == r.paquets.size() - 1) {
			cout << r.paquets[i] << endl;
		}
		else {
			cout << r.paquets[i] << ", ";
		}
	}
	cout << endl;
}

void capaPresentacio::consultarVideojocsPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta tots els videojocs **" << endl;
	TXconsultarVideojocs op = TXconsultarVideojocs();
	op.executar();
	cout << "Informacio sobre els videojocs..." << endl;
	vector<TXconsultarVideojocs::res> r = op.obteResultat();
	for (int i = 0; i < r.size(); i++) {
		cout << "Nom videojoc: " << r[i].nom << endl;
		cout << "Descripcio: " << r[i].desc << endl;
		cout << "Qualificacio edat: " << r[i].qualificacio << endl;
		cout << "Genere: " << r[i].genere << endl;
		cout << "Data llancament: " << r[i].data << endl;
		cout << "Preu: " << r[i].preu << " euros" << endl;
		cout << "Paquets on esta inclos: ";
		for (int j = 0; j < r[i].paquets.size(); j++) {
			if (j == r[i].paquets.size() - 1) {
				cout << r[i].paquets[j];
			}
			else {
				cout << r[i].paquets[j] << ", ";
			}
		}
		if (i != r.size() - 1) cout << endl << "-----------------------------" << endl;
	}
	cout << endl << endl;
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
