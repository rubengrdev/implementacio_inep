#include "cercadoraConte.h"

cercadoraConte::cercadoraConte() {
	
}

cercadoraConte::~cercadoraConte() {

}

vector<passarelaConte> cercadoraConte::cerca(string n){
	vector<passarelaConte> res;
	string comanda = "SELECT * FROM public.\"Conte\" WHERE paquet = " + n + " OR videojoc = " + n + ";";
	pqxx::connection conn("dbname=postgres user=postgres password=1234 hostaddr=127.0.0.1 port=5432");
	pqxx::work txn = pqxx::work(conn);
	pqxx::result  q = txn.exec(comanda);
	txn.commit();
	for (int i = 0; i < q.size(); i++) {
		res.push_back(passarelaConte(q[i][1].c_str(), q[i][0].c_str()));
	}
	return res;
}
