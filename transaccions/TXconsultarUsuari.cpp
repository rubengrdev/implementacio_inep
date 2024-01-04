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

    cercadoraUsuari cercador = cercadoraUsuari();
    
    try {
        passarelaUsuari pus = cercador.cercaPerSobrenom(sn);
        resultat.nom = pus.getNom();
        resultat.sobrenom = pus.getSobrenom();
        resultat.correu = pus.getCorreu();
        resultat.dataNaixement = pus.getDataNaixement();
    } catch(const std::exception& e) {
        // Llançar excepció si no trobem l'usuari
        throw exception("Usuari no trobat: " + std::string(e.what()));
    }
}

TXconsultarUsuari::res TXconsultarUsuari::obteResultat() {
    return resultat;
}
