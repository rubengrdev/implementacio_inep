#include "TXcomprarPaquet.h"
#include "cercadoraElementCompra.h"
#include "cercadoraPaquetVideojocs.h"
#include "Videoconsola.h"
#include "passarelaCompra.h"
#include <ctime>
#include <string>

TXcomprarPaquet::TXcomprarPaquet(string nom) : nomPaquet(nom) {
    // Constructor
}

TXcomprarPaquet::~TXcomprarPaquet() {
    // Destructor
}

void TXcomprarPaquet::executar() {
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraPaquetVideojocs cercadorPa = cercadoraPaquetVideojocs();

    passarelaElementCompra el = cercadorEl.cercaPerNom(nomPaquet);
    passarelaPaquetVideojocs pa = cercadorPa.cercaPerNom(nomPaquet);

    if (!el.isValid() || !pa.isValid()) {
        throw std::runtime_error("Paquet no trobat");
    }

    Videoconsola& v = Videoconsola::getInstance();
    string usuari = v.getUsuari();

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = std::to_string(temps.tm_year + 1900) + "-" + std::to_string(temps.tm_mon + 1) + "-" + std::to_string(temps.tm_mday);
    
    passarelaCompra compra = passarelaCompra(usuari, nomPaquet, data, el.getPreu());
    compra.insereix();

    // Potser cal actualitzar l'estat de l'usuari o del paquet després de la compra.

    resultat = true; // Suposant que resultat és un booleà que indica si la transacció ha estat exitosa.
}

vector<TXcomprarPaquet::res> TXcomprarPaquet::obteResultat() {
    return resultat;
}
