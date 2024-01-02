#include "TXconsultarCompres.h"

TXconsultarCompres::TXconsultarCompres() {
    // Constructor
}

TXconsultarCompres::~TXconsultarCompres() {
    // Destructor
}

void TXconsultarCompres::executar() {
    cercadoraCompra comp = cercadoraCompra();
    cercadoraElementCompra el = cercadoraElementCompra();

    Videoconsola& consola = Videoconsola::getInstance();
    string usuari = consola.getUsuari();

    vector<passarelaCompra> pcom = comp.cercaPerUsuari(usuari);

    double total = 0;

    for (int i = 0; i < pcom.size(); i++) {
        element e = element();
        e.nom = pcom[i].getElement();
        passarelaElementCompra pel = el.cercaPerNom(e.nom);
        e.desc = pel.getDescripcio();
        e.tipus = pel.getTipus();
        e.preu = pcom[i].getPreu();
        e.data = pcom[i].getData();
        if (e.tipus == "paquet") {
            cercadoraConte con = cercadoraConte();
            vector<passarelaConte> pcon = con.cerca(e.nom);
            for (int j = 0; j < pcon.size(); j++) {
                passarelaElementCompra videojoc = el.cercaPerNom(pcon[i].getVideojoc());
                e.nomv.push_back(videojoc.getNom());
                e.descv.push_back(videojoc.getDescripcio());
            }
        }
        total += e.preu;
        resultat.elements.push_back(e);
    }
    resultat.total = total;
}

TXconsultarCompres::res TXconsultarCompres::obteResultat() {
    return resultat;
}
