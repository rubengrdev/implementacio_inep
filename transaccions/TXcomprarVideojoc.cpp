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
    passarelaVideojoc pvid;
    passarelaElementCompra pel;

    try {
        pvid = cercadorVid.cercaPerNom(nom);
        pel = cercadorEl.cercaPerNom(nom);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error en la compra del videojoc: " + std::string(e.what()));
    }

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = std::to_string(temps.tm_year + 1900) + "-" + std::to_string(temps.tm_mon + 1) + "-" + std::to_string(temps.tm_mday);

    passarelaCompra compra = passarelaCompra(usuari, nom, data, pel.getPreu());
    compra.insereix();

    resultat = true;  // Suposant que resultat és un booleà que indica si la transacció ha estat exitosa.
}

bool TXcomprarVideojoc::obteResultat() {
    return resultat;
}
