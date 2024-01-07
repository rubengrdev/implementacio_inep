#include "capaPresentacio.h"

capaPresentacio& capaPresentacio::getInstance() {
	static capaPresentacio instance;
	return instance;
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
	if (!comprovarCorreu(correuE)) {
		cout << "Error: Correu no valid." << endl;
		return;
	}
	cout << "Data de naixement (DD/MM/AAAA): ";
	getline(cin, dataN);
	if (!comprovarData(dataN)) {
		cout << "Error: Data no valida" << endl;
		return;
	}
	TXregistrarUsuari op = TXregistrarUsuari(nom, sobrenom, contrasenya, correuE, dataFormatter(dataN));
	try {
		op.executar();
	}
	catch (exception &e) {
		cout << "Usuari no registrat: " << e.what() << endl;
		return;
	}
	cout << "Usuari registrat correctament!" << endl;
}

void capaPresentacio::consultarUsuariPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta usuari **" << endl;
	TXconsultarUsuari op1 = TXconsultarUsuari();
	try {
		op1.executar();
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	TXconsultarUsuari::res r1 = op1.obteResultat();
	cout << "Nom complet: " << r1.nom << endl;
	cout << "Sobrenom: " << r1.sobrenom << endl;
	cout << "Correu electronic: " << r1.correu << endl;
	cout << "Data naixement (DD/MM/AAAA): " << dataFormatter(r1.dataN) << endl;
	cout << endl;
	TXconsultarCompres op2 = TXconsultarCompres();
	try {
		op2.executar();
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	TXconsultarCompres::res r2 = op2.obteResultat();
	cout << r2.videojocs << " videojocs comprats." << endl;
	cout << r2.paquets << " paquets de videojocs comprats." << endl;
	cout << r2.total << " euros gastats en total." << endl << endl;
}

void capaPresentacio::modificarUsuariPres() {
	cin.ignore();
	system("CLS");
	string input;
	cout << "** Modifica usuari **" << endl << endl;
	CUmodificaUsuari op = CUmodificaUsuari();
	TXconsultarUsuari::res r = op.consultaUsuari();
	cout << "Nom complet: " << r.nom << endl;
	cout << "Sobrenom: " << r.sobrenom << endl;
	cout << "Correu electronic " << r.correu << endl;
	cout << "Data naixement (DD/MM/AAAA): " << dataFormatter(r.dataN) << endl << endl;
	cout << "*********************************************" << endl;
	cout << "Omplir la informacio que es vol modificar ..." << endl;
	cout << "Nom complet: ";
	getline(cin, input);
	if (input.size() != 0) r.nom = input;
	cout << "Contrasenya: ";
	getline(cin, input);
	if (input.size() != 0) r.contrasenya = input;
	cout << "Correu electronic: ";
	getline(cin, input);
	if (input.size() != 0) r.correu = input;
	cout << "Data naixement (DD/MM/AAAA): ";
	getline(cin, input);
	if (!comprovarData(input)) {
		cout << "Error: Data no valida." << endl;
		return;
	}
	if (input.size() != 0) r.dataN = input;
	op.modificaUsuari(r.nom, r.contrasenya, r.correu, dataFormatter(r.dataN));
	cout << endl << "** Dades usuari modificades **" << endl;
	r = op.consultaUsuari();
	cout << "Nom complet: " << r.nom << endl;
	cout << "Sobrenom: " << r.sobrenom << endl;
	cout << "Correu electronic " << r.correu << endl;
	cout << "Data naixement (DD/MM/AAAA): " << dataFormatter(r.dataN) << endl << endl;
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
	string vid;
	cout << "** Comprar videojoc **" << endl;
	cout << "Nom videojoc: ";
	getline(cin, vid);
	TXconsultarVideojoc op1 = TXconsultarVideojoc(vid);
	try {
		op1.executar();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
		return;
	}
	cout << "Informacio sobre el videojoc..." << endl;
	TXconsultarVideojoc::res r = op1.obteResultat();
	cout << "Nom videojoc: " << r.nom << endl;
	cout << "Descripcio: " << r.desc << endl;
	cout << "Qualificacio edat: " << r.qualificacio << endl;
	cout << "Genere: " << r.genere << endl;
	cout << "Data llancament: " << dataFormatter(r.data) << endl;
	cout << "Preu: " << r.preu << " euros" << endl;
	cout << endl;
	cout << "Vols continuar amb la compra (S/N): ";
	char conf;
	cin >> conf;
	TXcomprarVideojoc op2 = TXcomprarVideojoc(vid);
	if (conf == 'S') {
		try {
			op2.executar();
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl << endl;
			return;
		}
	}
	else return;
	TXcomprarVideojoc::res rec = op2.obteResultat();
	cout << endl << "Compra registrada: " << dataFormatter(rec.data) << endl << endl;
	cout << "Jocs relacionats : " << endl;
	for (int i = 0; i < rec.recomanats.size(); i++) {
		cout << "- " << rec.recomanats[i].nom << "; " << rec.recomanats[i].desc << "; " << rec.recomanats[i].preu << " euros" << endl;
	}
	cout << endl;
}

void capaPresentacio::comprarPaquetPres() {
	cin.ignore();
	system("CLS");
	string paq;
	cout << "** Comprar paquet **" << endl;
	cout << "Nom paquet: ";
	getline(cin, paq);
	TXconsultarPaquet op1 = TXconsultarPaquet(paq);
	try {
		op1.executar();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
		return;
	}
	cout << "Informacio sobre el paquet..." << endl;
	TXconsultarPaquet::res r = op1.obteResultat();
	cout << "Nom paquet: " << r.nom << endl;
	cout << "Descripcio: " << r.desc << endl;
	cout << "Preu: " << r.preu << " euros (estalvi de " << r.estalvi << " euros)" << endl;
	cout << endl;
	cout << "Jocs inclosos: " << endl << endl;
	for (int i = 0; i < r.vnoms.size(); i++) {
		cout << "> " << r.vnoms[i] << "; " << r.vdescs[i] << "; " << r.vpreus[i] << " euros" << endl;
	}
	cout << endl << "Vols continuar amb la compra (S/N): ";
	char conf;
	cin >> conf;
	TXcomprarPaquet op2 = TXcomprarPaquet(paq);
	if (conf == 'S') {
		try {
			op2.executar();
			string res = op2.obteResultat();
			cout << endl << "Compra registrada: " << dataFormatter(res) << endl;
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl << endl;
			return;
		}
	}
	else return;
}

void capaPresentacio::consultarCompresPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta compres **" << endl << endl;
	TXconsultarCompres op = TXconsultarCompres();
	try {
		op.executar();
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	TXconsultarCompres::res r = op.obteResultat();
	for (int i = 0; i < r.elements.size(); i++) {
		cout << dataFormatter(r.elements[i].data) << " " << r.elements[i].tipus << " " << r.elements[i].nom << "; " << r.elements[i].desc << "; " << r.elements[i].preu << " euros" << endl;
		if (r.elements[i].tipus == "paquet") {
			cout << "    Videojocs:" << endl;
			for (int j = 0; j < r.elements[i].nomv.size(); j++) cout << "        " << r.elements[i].nomv[j] << "; " << r.elements[i].descv[j] << endl;
		}
		cout << endl;
	}
	cout << "Total: " << r.total << " euros." << endl;
	cout << endl;
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
	cout << "Data llancament: " << dataFormatter(r.data) << endl;
	cout << "Preu: " << r.preu << " euros" << endl;
	cout << "Paquets on esta inclos: ";
	for (int i = 0; i < r.paquets.size(); i++) {
		if (i == r.paquets.size() - 1) cout << r.paquets[i] << endl;
		else cout << r.paquets[i] << ", ";
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
		cout << "Data llancament: " << dataFormatter(r[i].data) << endl;
		cout << "Preu: " << r[i].preu << " euros" << endl;
		cout << "Paquets on esta inclos: ";
		for (int j = 0; j < r[i].paquets.size(); j++) {
			if (j == r[i].paquets.size() - 1) cout << r[i].paquets[j];
			else cout << r[i].paquets[j] << ", ";
		}
		if (i != r.size() - 1) cout << endl << "-----------------------------" << endl;
	}
	cout << endl << endl;
}
void capaPresentacio::consultarVideojocsEdatPres() {
	cin.ignore();
	system("CLS");
	int edat;
	cout << "** Consulta videojocs per edat **" << endl;
	cout << "Edat maxima (anys): ";
	cin >> edat;
	TXconsultarVideojocsPerEdat op = TXconsultarVideojocsPerEdat(edat);
	op.executar();
	cout << "** Consulta videojocs fins a " << edat << " anys **" << endl << endl;
	vector<TXconsultarVideojocsPerEdat::res> r = op.obteResultat();
	for (int i = 0; i < r.size(); i++) {
		cout << r[i].nom << "; " << r[i].desc << "; " << r[i].preu << "; " << r[i].qualificacio << " PEGI" << "; " << r[i].genere << "; " << dataFormatter(r[i].data);
		if (r[i].paquets.size() != 0) cout << "; Paquets: ";
		for (int j = 0; j < r[i].paquets.size(); j++) {
			if (j == r[i].paquets.size() - 1) cout << r[i].paquets[j];
			else cout << r[i].paquets[j] << ", ";
		}
		if (i != r.size() - 1) cout << endl << endl;
	}
	cout << endl << endl;
}

void capaPresentacio::consultarNovetatsPres() {
	cin.ignore();
	system("CLS");
	string data;
	cout << "** Consulta novetats **" << endl;
	cout << "Data (DD/MM/AAAA): ";
	getline(cin, data);
	if (!comprovarData(data)) {
		cout << "Error: Data no valida." << endl;
		return;
	}
	TXconsultarNovetats op = TXconsultarNovetats(dataFormatter(data));
	op.executar();
	vector<TXconsultarNovetats::res> r = op.obteResultat();
	cout << endl;
	for (int i = 0; i < r.size(); i++) {
		cout << r[i].nom << "; " << r[i].desc << "; " << r[i].preu << " euros; " << r[i].qualificacio << " PEGI; " << r[i].genere << "; " << dataFormatter(r[i].data);
		if (r[i].paquets.size() != 0) cout << "; Paquets: ";
		for (int j = 0; j < r[i].paquets.size(); j++) {
			if (j == r[i].paquets.size() - 1) cout << r[i].paquets[j];
			else cout << r[i].paquets[j] << ", ";
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
	cout << endl;
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
