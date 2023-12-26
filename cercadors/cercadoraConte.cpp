#include "cercadoraConte.h"

cercadoraConte::cercadoraConte() {
	conn = pqxx::connection("dbname=implementacio_inep user=postgres password=1234 hostaddr = 127.0.0.1 port = 5432");
}

cercadoraConte::~cercadoraConte() {

}

//Mirar si es poden unificar les dues operacions, ja que son gairebe identiques

vector<passarelaConte> cercadoraConte::cercaPerVideojoc(string nomV){
	vector<passarelaConte> res;
	string comanda = "SELECT * FROM public.\"Conte\" WHERE videojoc = " + nomV + ";";
	pqxx::work txn = pqxx::work(conn);
	pqxx::result  q = txn.exec(comanda);
	for (int i = 0; i < q.size(); i++) {
		res.push_back(passarelaConte(q[i][1].c_str(), q[i][0].c_str()));
	}
	return res;
}

vector<passarelaConte> cercadoraConte::cercaPerPaquet(string nomP){
	vector<passarelaConte> res;
	string comanda = "SELECT * FROM public.\"Conte\" WHERE paquet = " + nomP + ";";
	pqxx::work txn = pqxx::work(conn);
	pqxx::result  q = txn.exec(comanda);
	for (int i = 0; i < q.size(); i++) {
		res.push_back(passarelaConte(q[i][1].c_str(), q[i][0].c_str()));
	}
	return res;
}
