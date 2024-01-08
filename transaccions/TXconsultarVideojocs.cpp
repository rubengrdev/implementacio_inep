#include "TXconsultarVideojocs.h"

// Constructora
TXconsultarVideojocs::TXconsultarVideojocs() {
}

// Destructora
TXconsultarVideojocs::~TXconsultarVideojocs() {
}

// executar: Cerca tots els videojocs disponibles
// Pre: Cap
// Post: 'resultat' conté la llista de tots els videojocs amb la seva informació
void TXconsultarVideojocs::executar(){
    cercadoraElementCompra el = cercadoraElementCompra();
    vector<passarelaElementCompra> pel = el.totsVideojocs(); // Obté tots els videojocs

    for (int i = 0; i < pel.size(); i++) {
        if (pel[i].getTipus() == "videojoc") {
            cercadoraVideojoc vid = cercadoraVideojoc();
            passarelaVideojoc pvid = vid.cercaPerNom(pel[i].getNom());
            cercadoraConte con = cercadoraConte();
            vector<passarelaConte> pcon = con.cerca(pel[i].getNom()); // Cerca els paquets on està inclòs el videojoc

            res r; // Prepara objecte per emmagatzemar dades del videojoc
            r.nom = pel[i].getNom();
            r.desc = pel[i].getDescripcio();
            r.preu = pel[i].getPreu();
            r.genere = pvid.getGenere();
            r.data = pvid.getDataLlan();
            r.qualificacio = pvid.getQualificacio();
            for (auto &paquet : pcon) r.paquets.push_back(paquet.getPaquet()); // Afegeix paquets on està inclòs
            resultat.push_back(r); // Afegeix a la llista de resultats
        }
    }
}

// obteResultat: Retorna llista de videojocs consultats
// Pre: 'executar' ha estat cridat
// Post: Retorna 'resultat' amb la llista de videojocs
vector<TXconsultarVideojocs::res> TXconsultarVideojocs::obteResultat() {
    return resultat;
}
