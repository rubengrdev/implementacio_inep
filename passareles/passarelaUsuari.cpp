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

void passarelaUsuari::insereix() {
	/*try {
		pqxx::connection conn("dbname=postgres user=postgres password=1234 hostaddr = 127.0.0.1 port = 5432");
		if (conn.is_open()) {
			cout << "Connexio exitosa amb la base de dades." << endl;
			pqxx::work txn(conn);
			string comanda = "INSERT INTO public.Usuari VALUES('"+sobrenom+"', '"+nom+"', '"+contrasenya+"', '"+correuE+"', '"+dataN+"');";
			pqxx::result result = txn.exec(comanda);
			txn.commit();
		}
		else {
			cerr << "Error de connexio amb la base de dades." << endl << endl;
		}

	}catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}*/
}

void passarelaUsuari::modifica() {

}

void passarelaUsuari::esborra() {

}