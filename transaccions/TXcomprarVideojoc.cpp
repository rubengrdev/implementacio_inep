#include "TXcomprarVideojoc.h"

TXcomprarVideojoc::TXcomprarVideojoc(string n) : nom(n) {
    // Constructor
}

TXcomprarVideojoc::~TXcomprarVideojoc() {
    // Destructor
}

void TXcomprarVideojoc::executar() {
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraVideojoc cercadorVid = cercadoraVideojoc();
    Videoconsola& consola = Videoconsola::getInstance();
    string usuari = consola.getUsuari();

    passarelaVideojoc pvid = cercadorVid.cercaPerNom(nom);
    passarelaElementCompra pel = cercadorEl.cercaPerNom(nom);

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year + 1900) + "-" + to_string(temps.tm_mon + 1) + "-" + to_string(temps.tm_mday);

    passarelaCompra compra = passarelaCompra(usuari, nom, data, pel.getPreu());
    compra.insereix();

}

TXcomprarVideojoc::res TXcomprarVideojoc::obteResultat() {
    return resultat;
}
