#include "cercadoraUsuari.h"

// Constructor: Inicialitza l'objecte sense paràmetres específics.
cercadoraUsuari::cercadoraUsuari() {
}

// Destructor: Neteja recursos si és necessari.
cercadoraUsuari::~cercadoraUsuari() {
}

// cercaPerSobrenom: Busca un usuari per sobrenom en la base de dades.
passarelaUsuari cercadoraUsuari::cercaPerSobrenom(string sn) {
    string comanda = "SELECT * FROM usuari WHERE sobrenom = '" + sn + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexió amb la base de dades.
        pqxx::work txn(conn); // Inicia una transacció.
        q = txn.exec1(comanda); // Executa la consulta SQL.
        txn.commit(); // Finalitza la transacció.
    } catch(...) {
        throw exception("No existeix l'usuari a buscar");
    }
    return passarelaUsuari(q[1].c_str(), q[0].c_str(), q[2].c_str(), q[3].c_str(), q[4].c_str()); // Retorna el resultat.
}
