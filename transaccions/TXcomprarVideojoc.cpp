#include "TXcomprarVideojoc.h"

TXcomprarVideojoc::TXcomprarVideojoc(string n) {
    // Constructor
    nom = n;
}

TXcomprarVideojoc::~TXcomprarVideojoc() {
    // Destructor
}

void TXcomprarVideojoc::executar() {
    // Suposem que tenim un nom d'usuari i un nom de videojoc com a atributs de la classe
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraVideojoc cercadorVid = cercadoraVideojoc();
    Videoconsola& consola = Videoconsola::getInstance();
    string usuari = consola.getUsuari();
    passarelaVideojoc pvid = cercadorVid.cercaPerNom(nom);
    passarelaElementCompra pel = cercadorEl.cercaPerNom(nom);
    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year) + "-" + to_string(temps.tm_mon) + "-" + to_string(temps.tm_mday);
    passarelaCompra compra = passarelaCompra(usuari, nom, data, pel.getPreu());
    compra.insereix();

    // Aquí s'ha de gestionar la lògica de la compra del videojoc.
    // Això podria incloure registrar la compra a la base de dades, verificar saldos, etc.
    // Aquesta part depèn de l'esquema i la lògica de negoci del teu sistema.

    // Commit de la transacció, o rollback en cas d'error.
}

// Aquest mètode pot retornar informació sobre el resultat de la transacció
// Depèn del que vulguis retornar
// per exemple, si la compra ha estat exitosa, detalls de la compra, etc.
TXcomprarVideojoc::res TXcomprarVideojoc::obteResultat() {
    return resultat;
}
