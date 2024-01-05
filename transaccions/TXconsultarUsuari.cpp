#include "TXconsultarUsuari.h"

//Constructora
TXconsultarUsuari::TXconsultarUsuari() {
    
}

//Destructora
TXconsultarUsuari::~TXconsultarUsuari() {
    
}

//executar: Crida per executar.
void TXconsultarUsuari::executar() {
    Videoconsola& vid = Videoconsola::getInstance();
    string sn = vid.getUsuari(); //Obte el sobrenom d'usuari a partir de la videoconsola.

    //Obte la passarela d'usuari a partir del sobrenom.
    cercadoraUsuari cercador = cercadoraUsuari();
    passarelaUsuari pus = cercador.cercaPerSobrenom(sn);
    
    //Emplena la informacio del resultat amb l'usuari.
    resultat.nom = pus.getNom();
    resultat.sobrenom = pus.getSobrenom();
    resultat.correu = pus.getCorreu();
    resultat.dataN = pus.getDataN();
    resultat.contrasenya = pus.getContrasenya();
}

//obteResultat: Crida per retornar el resultat.
TXconsultarUsuari::res TXconsultarUsuari::obteResultat() {
    return resultat; //Retorna el resultat
}
