#include "TXcomprarVideojoc.h"
#include "cercadoraElementCompra.h"
#include "cercadoraVideojoc.h"
#include "Videoconsola.h"
#include "passarelaCompra.h"
#include <ctime>
#include <string>

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

    if (!pvid.isValid() || !pel.isValid()) {
        throw std::runtime_error("Videojoc no trobat");
    }

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = std::to_string(temps.tm_year + 1900) + "-" + std::to_string(temps.tm_mon + 1) + "-" + std::to_string(temps.tm_mday);

    passarelaCompra compra = passarelaCompra(usuari, nom, data, pel.getPreu());
    compra.insereix();

    //potser caldria actualitzar l'estat de l'usuari o del videojoc.

    resultat = true;  // Suposant que resultat és un booleà que indica si la transacció ha estat exitosa.
}

bool TXcomprarVideojoc::obteResultat() {
    return resultat;
}

