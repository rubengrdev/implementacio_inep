#include "cercadoraVideojoc.h"

cercadoraVideojoc::cercadoraVideojoc() {
    // Constructor
}

cercadoraVideojoc::~cercadoraVideojoc() {
    // Destructor
}

passarelaVideojoc cercadoraVideojoc::cercaPerNom(string n) {
    string comanda = "SELECT * FROM public.\"Videojoc\" WHERE nom = '" + n + "';";
    pqxx::row q;

    try {
        pqxx::connection conn(PARAMS);
        pqxx::work txn(conn);
        q = txn.exec1(comanda);
        txn.commit();
    } catch(...) {
        throw exception("No existeix el videojoc a buscar");
    }

    passarelaVideojoc res = passarelaVideojoc(q[0].c_str(), q[1].c_str(), q[2].as<int>(), q[3].c_str(), q[4].as<int>());
    return res;
}
