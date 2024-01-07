#include "cercadoraPaquetVideojocs.h"

// Constructor: Inicialitza l'objecte sense parametres especifics.
cercadoraPaquetVideojocs::cercadoraPaquetVideojocs() {
}

// Destructor: Neteja recursos si es necessari.
cercadoraPaquetVideojocs::~cercadoraPaquetVideojocs() {
}

// cercaPerNom: Busca un paquet de videojocs per nom a la base de dades.
passarelaPaquetVideojocs cercadoraPaquetVideojocs::cercaPerNom(string nomP) {
    string comanda = "SELECT * FROM paquet_videojoc WHERE nom = '" + nomP + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
        pqxx::work txn(conn); // Inicia una transaccio.
        q = txn.exec1(comanda); // Executa la consulta SQL.
        txn.commit(); // Finalitza la transaccio.
    } catch(...) {
        //Si la consulta no retorna exactament una fila (excepcio de exec1), llença la excepcio PaquetVideojocsNoExisteix
        throw exception("No existeix el paquet a buscar");
    }
    return passarelaPaquetVideojocs(q[0].c_str()); // Retorna el resultat.
}

//preuJocs: Retorna el preu total de tots els videojocs que conte el paquet nomP
double cercadoraPaquetVideojocs::preuJocs(string nomP) {
    string comanda = "SELECT preu_jocs FROM preu_jocs WHERE nom_paquet = '" + nomP + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
        pqxx::work txn(conn); // Inicia una transaccio.
        q = txn.exec1(comanda); // Executa la consulta SQL.
        txn.commit(); // Finalitza la transaccio.
    }
    catch (...) {
        throw exception("No existeix el paquet a buscar");
    }
    return q[0].as<double>();
}
