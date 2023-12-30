 #include "cercadoraVideojoc.h"

cercadoraVideojoc::cercadoraVideojoc() {

}

cercadoraVideojoc::~cercadoraVideojoc() {

}

passarelaVideojoc cercadoraVideojoc::cercaPerNom(string n) {
	string comanda = "SELECT * FROM public.\"Videojoc\" WHERE nom = '" + n + "';";
	pqxx::row q;
	try {
		pqxx::connection conn(PARAMS);
		pqxx::work txn = pqxx::work(conn);
		q = txn.exec1(comanda);
		txn.commit();
	}
	catch(...) {
		throw exception("L'element no es un videojoc");
	}
	passarelaVideojoc res = passarelaVideojoc(q[0].c_str(), q[2].as<int>(), q[3].c_str(), q[1].c_str(), 0);
	return res;
}