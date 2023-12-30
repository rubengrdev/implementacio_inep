#include "cercadoraElementCompra.h"

cercadoraElementCompra::cercadoraElementCompra() {

}

cercadoraElementCompra::~cercadoraElementCompra() {

}

passarelaElementCompra cercadoraElementCompra::cercaPerNom(string n){
	string comanda = "SELECT * FROM public.\"ElementCompra\" WHERE nom = '" + n + "';";
	pqxx::row q;
	try {
		pqxx::connection conn(PARAMS);
		pqxx::work txn = pqxx::work(conn);
		q = txn.exec1(comanda);
		txn.commit();
	}
	catch(...){
		throw exception("No existeix l'element a buscar");
	}
	passarelaElementCompra res = passarelaElementCompra(q[0].c_str(), q[1].c_str(), q[2].as<double>(), q[3].c_str());
	return res;
}

vector<passarelaElementCompra> cercadoraElementCompra::totsVideojocs() {
	vector<passarelaElementCompra> res;
	string comanda = "SELECT * FROM public.\"ElementCompra\" INNER JOIN public.\"Videojoc\" ON \"ElementCompra\".nom = \"Videojoc\".nom ORDER BY \"Videojoc\".datallancament DESC;";
	pqxx::connection conn(PARAMS);
	pqxx::work txn = pqxx::work(conn);
	pqxx::result q = txn.exec(comanda);
	txn.commit();
	for (int i = 0; i < q.size(); i++) {
		res.push_back(passarelaElementCompra(q[i][0].c_str(), q[i][1].c_str(), q[i][2].as<double>(), q[i][3].c_str()));
	}
	return res;
}

vector<passarelaElementCompra> cercadoraElementCompra::totsPaquets() {
	vector<passarelaElementCompra> res;
	string comanda = "SELECT * FROM public.\"ElementCompra\" WHERE tipus = 'paquet';";
	pqxx::connection conn(PARAMS);
	pqxx::work txn = pqxx::work(conn);
	pqxx::result q = txn.exec(comanda);
	txn.commit();
	for (int i = 0; i < q.size(); i++) {
		res.push_back(passarelaElementCompra(q[i][0].c_str(), q[i][1].c_str(), q[i][2].as<double>(), q[i][3].c_str()));
	}
	return res;
}