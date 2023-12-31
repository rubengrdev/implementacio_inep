#include "TXcomprarVideojoc.h"
#include "cercadoraElementCompra.h"
#include "cercadoraUsuari.h"

TXcomprarVideojoc::TXcomprarVideojoc() {
    // Constructor
}

TXcomprarVideojoc::~TXcomprarVideojoc() {
    // Destructor
}

void TXcomprarVideojoc::executar() {
    // Suposem que tenim un nom d'usuari i un nom de videojoc com a atributs de la classe
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraUsuari cercadorUs = cercadoraUsuari();

    // Verificar existència del videojoc
    passarelaElementCompra videojoc = cercadorEl.cercaPerNom(nomVideojoc);
    if (!videojoc.isValid()) {
        throw std::runtime_error("Videojoc no trobat");
    }

    // Verificar usuari
    passarelaUsuari usuari = cercadorUs.cercaPerSobrenom(nomUsuari);
    if (!usuari.isValid()) {
        throw std::runtime_error("Usuari no trobat");
    }

    // Aquí s'ha de gestionar la lògica de la compra del videojoc.
    // Això podria incloure registrar la compra a la base de dades, verificar saldos, etc.
    // Aquesta part depèn de l'esquema i la lògica de negoci del teu sistema.

    // Commit de la transacció, o rollback en cas d'error.
}

// Aquest mètode pot retornar informació sobre el resultat de la transacció
// Depèn del que vulguis retornar
// per exemple, si la compra ha estat exitosa, detalls de la compra, etc.
TXcomprarVideojoc::Res TXcomprarVideojoc::obteResultat() {
    return resultat;
}
