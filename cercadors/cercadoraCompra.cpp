#include "cercadoraCompra.h"


cercadoraCompra::cercadoraCompra() {

}

cercadoraCompra::~cercadoraCompra() {

}

vector<passarelaCompra> cercadoraCompra::cercaPerUsuari(string u) {
    vector<passarelaCompra> res;
    pqxx::connection conn(PARAMS);
    pqxx::work txn(conn);
    string comanda = "SELECT * FROM compra WHERE usuari = '" + u + "' ORDER BY data DESC;";
    pqxx::result r = txn.exec(comanda);
    txn.commit();
    for (int i = 0; i < r.size(); i++) {
        res.push_back(passarelaCompra(r[i][0].c_str(), r[i][1].c_str(), r[i][2].c_str(), r[i][3].as<double>()));
    }
    return res;
}

passarelaCompra cercadoraCompra::cercaPerElement(string e) {
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS);
        pqxx::work txn = pqxx::work(conn);
        string comanda = "SELECT * FROM compra WHERE element = '" + e + "';";
        q = txn.exec1(comanda);
        txn.commit();
    }
    catch (...) {
        throw exception("No hi ha cap compra registrada amb l'element especificat");
    }
    return passarelaCompra(q[0].c_str(), q[1].c_str(), q[2].c_str(), q[3].as<double>());
}
