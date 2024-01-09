#include "passarelaUsuari.h"

//Constructora
passarelaUsuari::passarelaUsuari(string n, string sn, string c, string cE, string dN) {
	nom = n;
	sobrenom = sn;
	contrasenya = c;
	correuE = cE;
	dataN = dN;
}

//Destructora
passarelaUsuari::~passarelaUsuari() {

}

//Getters
string passarelaUsuari::getNom() {
    // Comprovem si 'this' és un punter nul, el que indicaria que l'objecte no està inicialitzat correctament.
    if (this == nullptr) {
        throw std::runtime_error("Error: L'objecte no està inicialitzat correctament.");
    }
    // Comprovem si la variable membre 'nom' està buida, el que indicaria que no s'ha establert per aquest objecte.
    if (nom.empty()) {
        throw std::runtime_error("Error: 'nom' no està definit per a aquest objecte.");
    }
    // Retornem el nom si totes les comprovacions són correctes.
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

//Setters
void passarelaUsuari::setNom(string n) {
	nom = n;
}

//No hi ha setter pel sobrenom ja que es l'id

void passarelaUsuari::setContrasenya(string c) {
	contrasenya = c;
}

void passarelaUsuari::setCorreu(string cE) {
	correuE = cE;
}

void passarelaUsuari::setDataN(string dN) {
	dataN = dN;
}

//Operacions sobre la BD
void passarelaUsuari::insereix() {
	pqxx::connection conn(PARAMS); //Crea la connexio amb la base de dades.
	pqxx::work txn(conn); //Crea la transaccio.
	string comanda = "INSERT INTO usuari VALUES('"+sobrenom+"', '"+nom+"', '"+contrasenya+"', '"+correuE+"', '"+dataN+"');";
	pqxx::result result = txn.exec(comanda); //Executa la comanda d'inserir.
	txn.commit(); //Finalitza la transaccio.
}

void passarelaUsuari::modifica() {
	pqxx::connection conn(PARAMS); //Crea la connexio amb la base de dades.
	pqxx::work txn = pqxx::work(conn); //Crea la transaccio.
	string comanda = "UPDATE usuari SET nom = '" + nom + "', contrasenya = '" + contrasenya + "', correu_electronic = '" + correuE + "', data_naixement = '" + dataN + "' WHERE sobrenom = '" + sobrenom + "';";
	txn.exec(comanda); //Executa la comanda de modificacio.
	txn.commit(); //Finalitza la transaccio.
}

void passarelaUsuari::esborra() {
	pqxx::connection conn(PARAMS); //Crea la connexio amb la base de dades.
	pqxx::work txn = pqxx::work(conn); //Crea la transaccio.
	string comanda = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom + "';";
	txn.exec(comanda); //Executa la comanda de modificacio.
	txn.commit(); //Finalitza la transaccio.
}