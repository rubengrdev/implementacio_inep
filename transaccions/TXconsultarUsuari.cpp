#include "TXconsultarUsuari.h"

TXconsultarUsuari::TXconsultarUsuari() {
    // Constructor
}

TXconsultarUsuari::~TXconsultarUsuari() {
    // Destructor
}

void TXconsultarUsuari::executar() {
    Videoconsola& vid = Videoconsola::getInstance();
    string sn = vid.getUsuari();
    cercadoraUsuari us = cercadoraUsuari();
    passarelaUsuari pus = us.cercaPerSobrenom(sn);

    // Comprovem si l'usuari existeix
    if (!pus.isValid()) {
        throw exception("Usuari no trobat");
    }

    // Emmagatzemar les dades de l'usuari en la variable 'resultat'
    resultat.nom = pus.getNom();
    resultat.sobrenom = pus.getSobrenom();
    resultat.correu = pus.getCorreu();
    resultat.dataNaixement = pus.getDataNaixement();
}

TXconsultarUsuari::res TXconsultarUsuari::obteResultat() {
    return resultat;
}
