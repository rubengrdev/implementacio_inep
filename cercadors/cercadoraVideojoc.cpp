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
    }
    catch (...) {
        throw exception("No existeix el videojoc a buscar");
    }
    return passarelaVideojoc(q[0].c_str(), q[2].as<int>(), q[3].c_str(), q[1].c_str(), 0);
}

vector<passarelaVideojoc> cercadoraVideojoc::cercaNovetats(string d) {
    vector<passarelaVideojoc> res;
    string comanda = "SELECT * FROM public.\"Videojoc\" WHERE datallancament >= '" + d + "' ORDER BY datallancament DESC;";
    pqxx::connection conn(PARAMS);
    pqxx::work txn(conn);
    pqxx::result r = txn.exec(comanda);
    txn.commit();
    for (int i = 0; i < r.size(); i++) {
        res.push_back(passarelaVideojoc(r[i][0].c_str(), r[i][2].as<int>(), r[i][3].c_str(), r[i][1].c_str(), 0));
    }
    return res;
}