#include "cercadoraPaquetVideojocs.h"

cercadoraPaquetVideojocs::cercadoraPaquetVideojocs() {
	
}

cercadoraPaquetVideojocs::~cercadoraPaquetVideojocs() {

}

passarelaPaquetVideojocs cercadoraPaquetVideojocs::cercaPerNom(string nomP) {
	string comanda = "SELECT * FROM public.\"PaquetVideojocs\" WHERE nom = '" + nomP + "';";
	pqxx::row q;
	try {
		pqxx::connection conn(PARAMS);
		pqxx::work txn = pqxx::work(conn);
		q = txn.exec1(comanda);
		txn.commit();
	}
	catch(...) {
		throw exception("L'element no es un paquet");
	}
	passarelaPaquetVideojocs res = passarelaPaquetVideojocs(q[0].c_str());
	return res;
}