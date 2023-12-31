#include "cercadoraPaquetVideojocs.h"

cercadoraPaquetVideojocs::cercadoraPaquetVideojocs() {
    // Constructor
}

cercadoraPaquetVideojocs::~cercadoraPaquetVideojocs() {
    // Destructor
}

passarelaPaquetVideojocs cercadoraPaquetVideojocs::cercaPerNom(string nomP) {
    string comanda = "SELECT * FROM public.\"PaquetVideojocs\" WHERE nom = '" + nomP + "';";
    pqxx::row q;

    try {
        pqxx::connection conn(PARAMS);
        pqxx::work txn(conn);
        q = txn.exec1(comanda);
        txn.commit();
    } catch(...) {
        throw exception("No existeix el paquet a buscar");
    }

    passarelaPaquetVideojocs res = passarelaPaquetVideojocs(q[0].c_str());
    return res;
}
