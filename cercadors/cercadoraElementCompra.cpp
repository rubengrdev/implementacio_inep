#include "cercadoraElementCompra.h"

// Constructor: Inicialitza l'objecte sense parametres especifics.
cercadoraElementCompra::cercadoraElementCompra() {
}

// Destructor: Neteja recursos si es necessari.
cercadoraElementCompra::~cercadoraElementCompra() {
}

// cercaPerNom: Realitza una consulta a la base de dades per trobar un element per nom.
passarelaElementCompra cercadoraElementCompra::cercaPerNom(string n) {
    string comanda = "SELECT * FROM element_compra WHERE nom = '" + n + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
        pqxx::work txn = pqxx::work(conn);
        q = txn.exec1(comanda); // Executa la consulta.
        txn.commit(); // Finalitza la transaccio.
    } catch(...) {
        //Si la consulta no retorna exactament una fila (excepcio de exec1), llença la excepcio ElementCompraNoExisteix
        throw exception("No existeix l'element a buscar");
    }
    return passarelaElementCompra(q[0].c_str(), q[1].c_str(), q[2].as<double>(), q[3].c_str()); // Retorna el resultat.
}

// totsVideojocs: Retorna tots els videojocs presents a la base de dades.
vector<passarelaElementCompra> cercadoraElementCompra::totsVideojocs() {
    vector<passarelaElementCompra> res;
    string comanda = "SELECT * FROM element_compra INNER JOIN videojoc ON element_compra.nom = videojoc.nom ORDER BY videojoc.data_llansament DESC;";
    pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
    pqxx::work txn = pqxx::work(conn);
    pqxx::result q = txn.exec(comanda); // Executa la consulta.
    txn.commit(); // Finalitza la transaccio
    for (int i = 0; i < q.size(); i++) {
        // Crea passareles d'elementCompra i les afegeix al vector
        res.push_back(passarelaElementCompra(q[i][0].c_str(), q[i][1].c_str(), q[i][2].as<double>(), q[i][3].c_str()));
    }
    return res; // Retorna la llista de videojocs.
}

// totsPaquets: Retorna tots els paquets presents a la base de dades.
vector<passarelaElementCompra> cercadoraElementCompra::totsPaquets() {
    vector<passarelaElementCompra> res;
    string comanda = "SELECT * FROM element_compra WHERE tipus = 'paquet';";
    pqxx::connection conn(PARAMS);
    pqxx::work txn = pqxx::work(conn);
    pqxx::result q = txn.exec(comanda);
    txn.commit();
    for (int i = 0; i < q.size(); i++) {
        res.push_back(passarelaElementCompra(q[i][0].c_str(), q[i][1].c_str(), q[i][2].as<double>(), q[i][3].c_str()));
    }
    return res; // Retorna la llista de paquets.
}
