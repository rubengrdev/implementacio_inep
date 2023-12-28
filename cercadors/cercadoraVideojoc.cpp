 #include "cercadoraVideojoc.h"

cercadoraVideojoc::cercadoraVideojoc() {

}

cercadoraVideojoc::~cercadoraVideojoc() {

}

passarelaVideojoc cercadoraVideojoc::cercaPerNom(string n) {
	string comanda = "SELECT * FROM public.\"Videojoc\" WHERE nom = '" + n + "';";
	pqxx::row q;
	try {
		pqxx::connection conn("dbname=postgres user=postgres password=1234 hostaddr=127.0.0.1 port=5432");
		pqxx::work txn = pqxx::work(conn);
		q = txn.exec1(comanda);
		txn.commit();
	}
	catch(const exception& e) {
		throw exception("L'element no es un videojoc");
	}
	passarelaVideojoc res = passarelaVideojoc(q[0].c_str(), q[2].as<int>(), q[3].c_str(), q[1].c_str(), 0);
	return res;
}