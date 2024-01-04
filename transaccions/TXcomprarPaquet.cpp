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

    passarelaElementCompra el = cercadorEl.cercaPerNom(nomPaquet);
    passarelaPaquetVideojocs pa = cercadorPa.cercaPerNom(nomPaquet);

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year + 1900) + "-" + to_string(temps.tm_mon + 1) + "-" + to_string(temps.tm_mday);

    passarelaCompra compra = passarelaCompra(usuari, nomPaquet, data, el.getPreu());
    compra.insereix();
}

vector<TXcomprarPaquet::res> TXcomprarPaquet::obteResultat() {
    return resultat;
}
    