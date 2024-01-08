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
    string usuari = consola.getUsuari();
    vector<passarelaCompra> pcom = comp.cercaPerUsuari(usuari);

    double total = 0;
    int paquets = 0, videojocs = 0;

    // Processa cada compra, incloent informació dels videojocs i paquets.
    for (auto& compra : pcom) {
        element e = element();
        e.ompleDades(compra, el);
        if (e.tipus == "paquet") paquets++;
        else videojocs++;
        total += e.preu;
        resultat.elements.push_back(e);
    }

    // Emplena el resultat amb la informació agregada.
    resultat.paquets = paquets;
    resultat.videojocs = videojocs;
    resultat.total = total;
}

// obteResultat: Retorna el resultat de la consulta.
// Pre: 'executar' ha estat cridat.
// Post: Retorna les dades de les compres realitzades.
TXconsultarCompres::res TXconsultarCompres::obteResultat() {
    return resultat;
}
