#include "TXcomprarPaquet.h"

TXcomprarPaquet::TXcomprarPaquet(string nom) {
    nomPaquet = nom;
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

    Videoconsola& v = Videoconsola::getInstance();
    string usuari = v.getUsuari();

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year) + "-" + to_string(temps.tm_mon) + "-" + to_string(temps.tm_mday);
    passarelaCompra compra = passarelaCompra(usuari, nomPaquet, data, el.getPreu());
    compra.insereix();
}

vector<TXcomprarPaquet::res> TXcomprarPaquet::obteResultat() {
    return resultat;
}
