#include "cercadoraUsuari.h"

cercadoraUsuari::cercadoraUsuari() {
    // Constructor
}

cercadoraUsuari::~cercadoraUsuari() {
    // Destructor
}

passarelaUsuari cercadoraUsuari::cercaPerSobrenom(string sn) {
    string comanda = "SELECT * FROM public.\"Usuari\" WHERE sobrenom = '" + sn + "';";
    pqxx::row q;

    try {
        pqxx::connection conn(PARAMS);
        pqxx::work txn(conn);
        q = txn.exec1(comanda);
        txn.commit();
    } catch(...) {
        throw exception("No existeix l'usuari a buscar");
    }

    passarelaUsuari res = passarelaUsuari(q[0].c_str(), q[1].c_str(), q[2].c_str(), q[3].c_str(), q[4].c_str());
    return res;
}
