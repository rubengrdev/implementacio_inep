#include "cercadoraPaquetVideojocs.h"

cercadoraPaquetVideojocs::cercadoraPaquetVideojocs() {
	conn = pqxx::connection("dbname=implementacio_inep user=postgres password=1234 hostaddr = 127.0.0.1 port = 5432");
}

cercadoraPaquetVideojocs::~cercadoraPaquetVideojocs() {

}

passarelaPaquetVideojocs cercadoraPaquetVideojocs::cercaPerNom(string nomP) {
	string comanda = "SELECT * FROM public.\"PaquetVideojocs\" WHERE nom = " + nomP + ";";
	pqxx::work txn = pqxx::work(conn);
	pqxx::result  q = txn.exec(comanda);
	passarelaPaquetVideojocs res = passarelaPaquetVideojocs(q[0][0].c_str());
	return res;
}