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
    cercadoraConte cercadorCon = cercadoraConte();

    Videoconsola& v = Videoconsola::getInstance();
    string usuari = v.getUsuari();

    passarelaElementCompra el = cercadorEl.cercaPerNom(nomPaquet);
    passarelaPaquetVideojocs pa = cercadorPa.cercaPerNom(nomPaquet);
    vector<passarelaConte> pcon = cercadorCon.cerca(nomPaquet);

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year + 1900) + "-" + to_string(temps.tm_mon + 1) + "-" + to_string(temps.tm_mday);

    for (int i = 0; i < pcon.size(); i++) {
        passarelaCompra vid = passarelaCompra(usuari, pcon[i].getVideojoc(), data, el.getPreu());
        try {
            vid.insereix();
        }
        catch (...) {
            //No importa si l'usuari ja ha comprat el videojoc anteriorment, per tant, si salta l'excepcio de compraJaExisteix, la ignorem.
        }
        
    }
    passarelaCompra compra = passarelaCompra(usuari, nomPaquet, data, el.getPreu());
    try {
        compra.insereix();
    }
    catch (...) {
        throw exception("Ja s'ha comprat el paquet.");
    }
    resultat = data;
}

string TXcomprarPaquet::obteResultat() {
    return resultat;
}
    