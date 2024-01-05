#include "cercadoraCompra.h"

// Constructor: Inicialitza la classe sense paràmetres específics.
cercadoraCompra::cercadoraCompra() {
}

// Destructor: Neteja recursos si és necessari.
cercadoraCompra::~cercadoraCompra() {
}

// cercaPerUsuari: Busca totes les compres d'un usuari específic.
vector<passarelaCompra> cercadoraCompra::cercaPerUsuari(string u) {
    vector<passarelaCompra> res;
    pqxx::connection conn(PARAMS); // Estableix connexió amb la base de dades.
    pqxx::work txn(conn); // Inicia una transacció.
    string comanda = "SELECT * FROM compra WHERE usuari = '" + u + "' ORDER BY data DESC;";
    pqxx::result r = txn.exec(comanda); // Executa la consulta.
    txn.commit(); // Finalitza la transacció.
    for (int i = 0; i < r.size(); i++) {
        // Crea objectes passarelaCompra amb les dades obtingudes.
        res.push_back(passarelaCompra(r[i][0].c_str(), r[i][1].c_str(), r[i][2].c_str(), r[i][3].as<double>()));
    }
    return res; // Retorna el resultat.
}

// cercaPerElement: Busca una compra per un element específic.
passarelaCompra cercadoraCompra::cercaPerElement(string e) {
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexió.
        pqxx::work txn = pqxx::work(conn);
        string comanda = "SELECT * FROM compra WHERE element = '" + e + "';";
        q = txn.exec1(comanda); // Executa la consulta.
        txn.commit();
    } catch (...) {
        throw exception("No hi ha cap compra registrada amb l'element especificat");
    }
    return passarelaCompra(q[0].c_str(), q[1].c_str(), q[2].c_str(), q[3].as<double>()); // Retorna la compra trobada.
}
