#include "TXconsultarCompres.h"
#include "cercadoraCompra.h"
#include <vector>

TXconsultarCompres::TXconsultarCompres() {
    // Constructor
}

TXconsultarCompres::~TXconsultarCompres() {
    // Destructor
}

void TXconsultarCompres::executar() {
    cercadoraCompra cercador = cercadoraCompra();
    // Aquí pots afegir el codi per a cercar compres.
    // Per exemple, cercar totes les compres d'un usuari específic.

    // Suposem que tenim un mètode per obtenir totes les compres
    vector<passarelaCompra> compres = cercador.totesLesCompres();

    for (const auto& compra : compres) {
        // Processar cada compra i afegir al resultat
        res r;
        r.nomVideojoc = compra.getNomVideojoc();
        r.preu = compra.getPreu();
        r.data = compra.getData();
        resultat.push_back(r);
    }
}

vector<TXconsultarCompres::res> TXconsultarCompres::obteResultat() {
    return resultat;
}
