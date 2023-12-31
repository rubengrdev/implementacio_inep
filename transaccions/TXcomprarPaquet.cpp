#include "TXcomprarPaquet.h"

TXcomprarPaquet::TXcomprarPaquet(string nom) {
    nomPaquet = nom;
    Videoconsola& v = Videoconsola::getInstance();
    usuari = v.getUsuari();
}

TXcomprarPaquet::~TXcomprarPaquet() {
    
}

void TXcomprarPaquet::executar() {
    // Suposem que tenim un nom d'usuari i un nom de paquet com a atributs de la classe
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraPaquetVideojocs cercadorPa = cercadoraPaquetVideojocs();

    // Verificar existència del paquet
    passarelaElementCompra el = cercadorEl.cercaPerNom(nomPaquet);
    passarelaPaquetVideojocs pa = cercadorPa.cercaPerNom(nomPaquet);

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year) + "-" + to_string(temps.tm_mon) + "-" + to_string(temps.tm_mday);
    passarelaCompra compra = passarelaCompra(usuari, nomPaquet, data, el.getPreu());
    compra.insereix();

    // Aquí s'ha de gestionar la lògica de la compra.
    // Per exemple, registrar la compra en una taula de compres, actualitzar estocs, etc.

    // Commit de la transacció, o rollback en cas d'error.
}
