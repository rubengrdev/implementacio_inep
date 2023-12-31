#include "TXconsultarNovetats.h"

TXconsultarNovetats::TXconsultarNovetats(string d) {
    // Constructor
    data = d;
}

TXconsultarNovetats::~TXconsultarNovetats() {
    // Destructor
}

void TXconsultarNovetats::executar() {
    cercadoraElementCompra el = cercadoraElementCompra();
    cercadoraVideojoc vid = cercadoraVideojoc();
    cercadoraConte co = cercadoraConte();
    vector<passarelaVideojoc> novetats = vid.cercaNovetats(data);
    for (int i = 0; i < novetats.size(); i++) {
        passarelaElementCompra pel = el.cercaPerNom(novetats[i].getNom());
        vector<passarelaConte> pco = co.cerca(novetats[i].getNom());
        res r = res();
        r.nom = pel.getNom();
        r.desc = pel.getDescripcio();
        r.preu = pel.getPreu();
        r.qualificacio = novetats[i].getQualificacio();
        r.data = novetats[i].getDataLlan();
        for (int j = 0; j < pco.size(); j++) {
            r.paquets.push_back(pco[j].getPaquet());
        }
        resultat.push_back(r);
    }
}

vector<TXconsultarNovetats::res> TXconsultarNovetats::obteResultat() {
    return resultat;
}
