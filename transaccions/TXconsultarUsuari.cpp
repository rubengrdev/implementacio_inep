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
    
    passarelaUsuari pus = cercador.cercaPerSobrenom(sn);
    resultat.nom = pus.getNom();
    resultat.sobrenom = pus.getSobrenom();
    resultat.correu = pus.getCorreu();
    resultat.dataN = pus.getDataN();
    resultat.contrasenya = pus.getContrasenya();
}

TXconsultarUsuari::res TXconsultarUsuari::obteResultat() {
    return resultat;
}
