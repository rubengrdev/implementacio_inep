#include "passarelaCompra.h"

passarelaCompra::passarelaCompra(string u, string e, string d, double p) {
	usuari = u;
	element = e;
	data = d;
	preuPagat = p;
}

passarelaCompra::~passarelaCompra() {

}

string passarelaCompra::getUsuari() {
	return usuari;
}

string passarelaCompra::getElement() {
	return element;
}

string passarelaCompra::getData() {
	return data;
}

double passarelaCompra::getPreu() {
	return preuPagat;
}

void passarelaCompra::insereix() {
	pqxx::connection conn(PARAMS);
	pqxx::work txn = pqxx::work(conn);
	string comanda = "INSERT INTO compra VALUES ('" + usuari + "', '" + element + "', '" + data + "', " + to_string(preuPagat) + ");";
	txn.exec(comanda);
	txn.commit();
}

void passarelaCompra::modifica() {

}

void passarelaCompra::esborra() {
	pqxx::connection conn(PARAMS);
	pqxx::work txn = pqxx::work(conn);
	string comanda = "DELETE FROM compra WHERE usuari = '" + usuari + "' AND element = '" + element + "';";
	txn.exec(comanda);
	txn.commit();
}