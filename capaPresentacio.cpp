#include "capaPresentacio.h"

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
	catch(...){
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
	try {
		op.executar();
		cout << "Usuari registrat correctament!" << endl;
	}
	catch (exception &e) {
		cout << "Usuari no registrat" << endl;
		cout << e.what() << endl;
		return;
	}
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

bool capaPresentacio::esborrarUsuariPres() {
	cin.ignore();
	system("CLS");
	string c;
	cout << "** Esborrar usuari **" << endl;
	cout << "Introdueix la teva contrasenya per confirmar l'esborrat: ";
	cin >> c;
	TXesborrarUsuari op = TXesborrarUsuari(c);
	try {
		op.executar();
		cout << "Usuari esborrat correctament!" << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	return op.obteResultat();
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
	TXconsultarNovetats op = TXconsultarNovetats(data);
	op.executar();
	vector<TXconsultarNovetats::res> r = op.obteResultat();
	cout << endl;
	for (int i = 0; i < r.size(); i++) {
		cout << r[i].nom << "; " << r[i].desc << "; " << r[i].preu << " euros; " << r[i].qualificacio << " PEGI; " << r[i].genere << "; " << r[i].data;
		if (r[i].paquets.size() != 0) {
			cout << "; Paquets: ";
			for (int j = 0; j < r[i].paquets.size(); j++) {
				if (j == r[i].paquets.size() - 1) {
					cout << r[i].paquets[j];
				}
				else {
					cout << r[i].paquets[j] << ", ";
				}
			}
		}
		cout << endl << endl;
	}
}

void capaPresentacio::consultarPaquetPres() {
	cin.ignore();
	system("CLS");
	string nPaquet;
	cout << "** Consulta paquet **" << endl;
	cout << "Nom paquet: ";
	getline(cin, nPaquet);
	TXconsultarPaquet op = TXconsultarPaquet(nPaquet);
	try {
		op.executar();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
		return;
	}
	TXconsultarPaquet::res r = op.obteResultat();
	cout << "Informacio paquet ..." << endl << endl;
	cout << "Nom paquet: " << r.nom << endl << endl;
	cout << "Descripcio: " << r.desc << endl << endl;
	cout << "Preu: " << r.preu << " euros (estalvi de " << r.estalvi << " euros)" << endl << endl;
	cout << endl;
	cout << "Jocs inclosos:" << endl;
	for (int i = 0; i < r.vnoms.size(); i++) cout << "- " << r.vnoms[i] << "; " << r.vdescs[i] << "; " << r.vpreus[i] << " euros" << endl << endl;
}

void capaPresentacio::consultarPaquetsPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta paquets **" << endl;
	TXconsultarPaquets op = TXconsultarPaquets();
	op.executar();
	vector<TXconsultarPaquets::res> v = op.obteResultat();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].nom << "; " << v[i].desc << "; " << v[i].preu << " euros (ESTALVI: " << v[i].estalvi << " euros)" << endl;
		cout << endl;
	}
}
