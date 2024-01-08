#include "TXconsultarPaquets.h"

// Constructora
TXconsultarPaquets::TXconsultarPaquets() {
}

// Destructora
TXconsultarPaquets::~TXconsultarPaquets() {
}

// executar: Realitza la consulta de tots els paquets
// Pre: Cap
// Post: 'resultat' conté informació de tots els paquets i l'estalvi que representen
void TXconsultarPaquets::executar(){
    cercadoraElementCompra el = cercadoraElementCompra();
    vector<passarelaElementCompra> pel = el.totsPaquets(); // Obté tots els paquets

    for (int i = 0; i < pel.size(); i++) {
        cercadoraConte co = cercadoraConte();
        vector<passarelaConte> pco = co.cerca(pel[i].getNom()); // Cerca contingut de cada paquet

        double total = calculaTotalPaquet(pco); // Calcula total dels preus dels videojocs inclosos

        res r; // Prepara objecte per emmagatzemar dades del paquet
        r.nom = pel[i].getNom();
        r.desc = pel[i].getDescripcio();
        r.preu = pel[i].getPreu();
        r.estalvi = total - r.preu; // Calcula l'estalvi
        resultat.push_back(r); // Afegeix a la llista de resultats
    }
}

// obteResultat: Retorna llista de paquets consultats
// Pre: 'executar' ha estat cridat
// Post: Retorna 'resultat' amb la llista de paquets i l'estalvi de cada un
vector<TXconsultarPaquets::res> TXconsultarPaquets::obteResultat() {
    return resultat;
}
