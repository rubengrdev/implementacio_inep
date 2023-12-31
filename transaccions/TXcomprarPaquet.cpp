#include "TXcomprarPaquet.h"
#include "cercadoraElementCompra.h"
#include "cercadoraUsuari.h"
// Fan falta més includes?

TXcomprarPaquet::TXcomprarPaquet() {
    // Constructor
}

TXcomprarPaquet::~TXcomprarPaquet() {
    // Destructor
}

void TXcomprarPaquet::executar() {
    // Suposem que tenim un nom d'usuari i un nom de paquet com a atributs de la classe
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraUsuari cercadorUs = cercadoraUsuari();

    // Verificar existència del paquet
    passarelaElementCompra paquet = cercadorEl.cercaPerNom(nomPaquet);
    if (!paquet.isValid()) {
        throw std::runtime_error("Paquet no trobat");
    }

    // Verificar usuari
    passarelaUsuari usuari = cercadorUs.cercaPerSobrenom(nomUsuari);
    if (!usuari.isValid()) {
        throw std::runtime_error("Usuari no trobat");
    }

    // Aquí s'ha de gestionar la lògica de la compra.
    // Per exemple, registrar la compra en una taula de compres, actualitzar estocs, etc.

    // Commit de la transacció, o rollback en cas d'error.
}

// Aquest mètode pot retornar informació sobre el resultat de la transacció
// Depèn del que vulguis retornar
// per exemple, si la compra ha estat exitosa, detalls de la compra, etc.
TXcomprarPaquet::Res TXcomprarPaquet::obteResultat() {
    return resultat;
}