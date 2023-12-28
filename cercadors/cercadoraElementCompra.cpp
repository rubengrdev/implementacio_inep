#include "cercadoraElementCompra.h"

cercadoraElementCompra::cercadoraElementCompra() {

}

cercadoraElementCompra::~cercadoraElementCompra() {

}

passarelaElementCompra cercadoraElementCompra::cercaPerNom(string n){
	string comanda = "SELECT * FROM public.\"ElementCompra\" WHERE nom = '" + n + "';";
	pqxx::row q;
	try {
		pqxx::connection conn("dbname=postgres user=postgres password=1234 hostaddr=127.0.0.1 port=5432");
		pqxx::work txn = pqxx::work(conn);
		q = txn.exec1(comanda);
		txn.commit();
	}
	catch(const exception& e){
		throw exception("No existeix l'element a buscar");
	}
	passarelaElementCompra res = passarelaElementCompra(q[0].c_str(), q[1].c_str(), q[2].as<double>(), q[3].c_str());
	return res;
}

vector<passarelaElementCompra> cercadoraElementCompra::totsElements() {
	vector<passarelaElementCompra> res;
	string comanda = "SELECT * FROM public.\"ElementCompra\";";
	pqxx::connection conn("dbname=postgres user=postgres password=1234 hostaddr=127.0.0.1 port=5432");
	pqxx::work txn = pqxx::work(conn);
	pqxx::result q = txn.exec(comanda);
	txn.commit();
	for (int i = 0; i < q.size(); i++) {
		res.push_back(passarelaElementCompra(q[i][0].c_str(), q[i][1].c_str(), q[i][2].as<double>(), q[i][3].c_str()));
	}
	return res;
}