#include "cercadoraCompra.h"

// Constructor: Inicialitza la classe sense parametres especifics.
cercadoraCompra::cercadoraCompra() {
}

// Destructor: Neteja recursos si es necessari.
cercadoraCompra::~cercadoraCompra() {
}

// cercaPerUsuari: Busca totes les compres d'un usuari en especific.
vector<passarelaCompra> cercadoraCompra::cercaPerUsuari(string u) {
    vector<passarelaCompra> res;
    pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
    pqxx::work txn(conn); // Inicia una transaccio.
    string comanda = "SELECT * FROM compra WHERE usuari = '" + u + "' ORDER BY data DESC;";
    pqxx::result r = txn.exec(comanda); // Executa la consulta.
    txn.commit(); // Finalitza la transaccio.
    for (int i = 0; i < r.size(); i++) {
        // Crea objectes passarelaCompra amb les dades obtingudes i els afegeix al vector a retornar.
        res.push_back(passarelaCompra(r[i][0].c_str(), r[i][1].c_str(), r[i][2].c_str(), r[i][3].as<double>()));
    }
    return res; // Retorna els resultats.
}

// cercaPerElement: Busca una compra per un element especific.
passarelaCompra cercadoraCompra::cercaPerElement(string e) {
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexio.
        pqxx::work txn = pqxx::work(conn);
        string comanda = "SELECT * FROM compra WHERE element = '" + e + "';";
        q = txn.exec1(comanda); // Executa la consulta.
        txn.commit();
    } catch (...) {
        throw exception("No hi ha cap compra registrada amb l'element especificat");
    }
    return passarelaCompra(q[0].c_str(), q[1].c_str(), q[2].c_str(), q[3].as<double>()); // Retorna la compra trobada.
}
