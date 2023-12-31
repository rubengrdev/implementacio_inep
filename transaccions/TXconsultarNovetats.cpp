#include "TXconsultarNovetats.h"
#include "cercadoraElementCompra.h"
#include <vector>

TXconsultarNovetats::TXconsultarNovetats() {
    // Constructor
}

TXconsultarNovetats::~TXconsultarNovetats() {
    // Destructor
}

void TXconsultarNovetats::executar() {
    cercadoraElementCompra cercador = cercadoraElementCompra();
    // Aquí pots afegir el codi per a cercar les novetats.
    // Per exemple, cercar tots els videojocs nous o els paquets recents.

    // Suposem que tenim un mètode per obtenir les novetats
    vector<passarelaElementCompra> novetats = cercador.novetats();

    for (const auto& novetat : novetats) {
        // Processar cada novetat i afegir al resultat
        res r;
        r.nom = novetat.getNom();
        r.desc = novetat.getDescripcio();
        r.preu = novetat.getPreu();
        resultat.push_back(r);
    }
}

vector<TXconsultarNovetats::res> TXconsultarNovetats::obteResultat() {
    return resultat;
}
