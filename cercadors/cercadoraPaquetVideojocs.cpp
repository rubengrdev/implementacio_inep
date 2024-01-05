#include "cercadoraPaquetVideojocs.h"

// Constructor: Inicialitza l'objecte sense paràmetres específics.
cercadoraPaquetVideojocs::cercadoraPaquetVideojocs() {
}

// Destructor: Neteja recursos si és necessari.
cercadoraPaquetVideojocs::~cercadoraPaquetVideojocs() {
}

// cercaPerNom: Busca un paquet de videojocs per nom a la base de dades.
passarelaPaquetVideojocs cercadoraPaquetVideojocs::cercaPerNom(string nomP) {
    string comanda = "SELECT * FROM paquet_videojoc WHERE nom = '" + nomP + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexió amb la base de dades.
        pqxx::work txn(conn); // Inicia una transacció.
        q = txn.exec1(comanda); // Executa la consulta SQL.
        txn.commit(); // Finalitza la transacció.
    } catch(...) {
        throw exception("No existeix el paquet a buscar");
    }
    return passarelaPaquetVideojocs(q[0].c_str()); // Retorna el resultat.
}
