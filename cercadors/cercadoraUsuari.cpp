#include "cercadoraUsuari.h"

cercadoraUsuari::cercadoraUsuari() {

}

cercadoraUsuari::~cercadoraUsuari() {

}

passarelaUsuari cercadoraUsuari::cercaPerSobrenom(string sn){
	pqxx::connection conn("dbname=postgres user=postgres password=1234 hostaddr=127.0.0.1 port=5432");
	pqxx::work txn(conn);
	string comanda = "SELECT * FROM public.\"musics\" WHERE sobrenom = " + sn + ";";
	try{
		pqxx::row q = txn.exec1(comanda);
	}catch(const exception& e){
		throw ("L'usuari especificat no existeix");
	}
	txn.commit();
	passarelaUsuari res = passarelaUsuari(q[1].c_str(), q[0].c_str(), q[2].c_str(), q[3].c_str(), q[4].c_str());
	return res;
}
