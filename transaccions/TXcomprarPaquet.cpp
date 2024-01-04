#include "TXcomprarPaquet.h"

TXcomprarPaquet::TXcomprarPaquet(string nom) : nomPaquet(nom) {
    // Constructor
}

TXcomprarPaquet::~TXcomprarPaquet() {
    // Destructor
}

void TXcomprarPaquet::executar() {
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraPaquetVideojocs cercadorPa = cercadoraPaquetVideojocs();
    Videoconsola& v = Videoconsola::getInstance();
    string usuari = v.getUsuari();
    passarelaElementCompra el;
    passarelaPaquetVideojocs pa;

    try {
        el = cercadorEl.cercaPerNom(nomPaquet);
        pa = cercadorPa.cercaPerNom(nomPaquet);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error en la compra del paquet: " + std::string(e.what()));
    }

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = std::to_string(temps.tm_year + 1900) + "-" + std::to_string(temps.tm_mon + 1) + "-" + std::to_string(temps.tm_mday);

    passarelaCompra compra = passarelaCompra(usuari, nomPaquet, data, el.getPreu());
    compra.insereix();

    resultat = true;  // Suposant que resultat és un booleà que indica si la transacció ha estat exitosa.
}

vector<TXcomprarPaquet::res> TXcomprarPaquet::obteResultat() {
    return resultat;
}
    