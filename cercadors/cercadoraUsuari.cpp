#include "cercadoraUsuari.h"

cercadoraUsuari::cercadoraUsuari() {

}

cercadoraUsuari::~cercadoraUsuari() {

}

passarelaUsuari cercadoraUsuari::cercaPerSobrenom(string sn){
	pqxx::connection conn(PARAMS);
	pqxx::work txn(conn);
	string comanda = "SELECT * FROM public.\"Usuari\" WHERE sobrenom = '" + sn + "';";
	pqxx::row q;
	try{
		q = txn.exec1(comanda);
	}catch(...){
		throw exception("Sobrenom incorrecte");
	}
	txn.commit();
	passarelaUsuari res = passarelaUsuari(q[1].c_str(), q[0].c_str(), q[2].c_str(), q[3].c_str(), q[4].c_str());
	return res;
}
