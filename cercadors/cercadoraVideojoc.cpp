#include "cercadoraVideojoc.h"

// Constructor: S'inicialitza l'objecte sense paràmetres específics.
cercadoraVideojoc::cercadoraVideojoc() {
}

// Destructor: Neteja recursos si és necessari.
cercadoraVideojoc::~cercadoraVideojoc() {
}

// cercaPerNom: Busca un videojoc per nom en la base de dades.
passarelaVideojoc cercadoraVideojoc::cercaPerNom(string n) {
    string comanda = "SELECT * FROM videojoc WHERE nom = '" + n + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexió amb la base de dades.
        pqxx::work txn(conn); // Inicia una transacció.
        q = txn.exec1(comanda); // Executa la consulta SQL.
        txn.commit(); // Finalitza la transacció.
    } catch (...) {
        throw exception("No existeix el videojoc a buscar");
    }
    return passarelaVideojoc(q[0].c_str(), q[2].as<int>(), q[3].c_str(), q[1].c_str(), 0); // Retorna el resultat.
}


// cercaNovetats: Retorna una llista de videojocs llançats des d'una data específica.
vector<passarelaVideojoc> cercadoraVideojoc::cercaNovetats(string d) {
    vector<passarelaVideojoc> res;
    string comanda = "SELECT * FROM videojoc WHERE data_llansament >= '" + d + "' ORDER BY data_llansament DESC;";
    pqxx::connection conn(PARAMS);
    pqxx::work txn(conn);
    pqxx::result r = txn.exec(comanda);
    txn.commit();
    for (int i = 0; i < r.size(); i++) {
        res.push_back(passarelaVideojoc(r[i][0].c_str(), r[i][2].as<int>(), r[i][3].c_str(), r[i][1].c_str(), 0));
    }
    return res;
}

// cercaPerEdat: Retorna videojocs que són adequats per a una edat específica o menys.
vector<passarelaVideojoc> cercadoraVideojoc::cercaPerEdat(int edat) {
    vector<passarelaVideojoc> res;
    string comanda = "SELECT * FROM videojoc WHERE qualificacio_edat <= " + to_string(edat) + " ORDER BY qualificacio_edat DESC;";
    pqxx::connection conn(PARAMS);
    pqxx::work txn(conn);
    pqxx::result r = txn.exec(comanda);
    txn.commit();
    for (int i = 0; i < r.size(); i++) {
        res.push_back(passarelaVideojoc(r[i][0].c_str(), r[i][2].as<int>(), r[i][3].c_str(), r[i][1].c_str(), 0));
    }
    return res;
}