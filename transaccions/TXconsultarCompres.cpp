#include "TXconsultarCompres.h"

// Constructor
TXconsultarCompres::TXconsultarCompres() {
}

// Destructor
TXconsultarCompres::~TXconsultarCompres() {
}

// executar: Realitza la consulta de compres d'un usuari.
// Pre: cap
// Post: Emplena 'resultat' amb les compres realitzades per l'usuari.
void TXconsultarCompres::executar() {
    cercadoraCompra comp = cercadoraCompra();
    cercadoraElementCompra el = cercadoraElementCompra();
    Videoconsola& consola = Videoconsola::getInstance();
    passarelaUsuari* usuari = consola.getUsuari();

    vector<passarelaCompra> pcom = comp.cercaPerUsuari(usuari -> getSobrenom());

    resultat.total = 0; resultat.paquets = 0; resultat.videojocs = 0;

    // Processa cada compra, incloent informació dels videojocs i paquets.
    for (int i = 0; i < pcom.size(); i++) {
        element e = element();
        e.nom = pcom[i].getElement();
        passarelaElementCompra pel = el.cercaPerNom(e.nom);
        if (pel.getPreu() == pcom[i].getPreu()) {
            e.desc = pel.getDescripcio();
            e.tipus = pel.getTipus();
            e.preu = pcom[i].getPreu();
            e.data = pcom[i].getData();
            if (e.tipus == "paquet") {
                resultat.paquets++;
                cercadoraConte con = cercadoraConte();
                vector<passarelaConte> pcon = con.cerca(e.nom);
                for (int j = 0; j < pcon.size(); j++) {
                    resultat.videojocs++;
                    passarelaElementCompra videojoc = el.cercaPerNom(pcon[j].getVideojoc());
                    e.nomv.push_back(videojoc.getNom());
                    e.descv.push_back(videojoc.getDescripcio());
                }
            }
            else resultat.videojocs++;
            resultat.total += e.preu;
            resultat.elements.push_back(e);
        }
    }
}

// obteResultat: Retorna el resultat de la consulta.
// Pre: 'executar' ha estat cridat.
// Post: Retorna les dades de les compres realitzades.
TXconsultarCompres::res TXconsultarCompres::obteResultat() {
    return resultat;
}
