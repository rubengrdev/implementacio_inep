#include "CUmodificaUsuari.h"

//Constructora
CUmodificaUsuari::CUmodificaUsuari() {

}

//Destructora
CUmodificaUsuari:: ~CUmodificaUsuari() {

}

//consultaUsuari: retorna informacio sobre l'usuari.
TXconsultarUsuari::res CUmodificaUsuari::consultaUsuari() {
	TXconsultarUsuari op = TXconsultarUsuari();
	op.executar();
	TXconsultarUsuari::res r = op.obteResultat();
	return r;
}

//modificaUsuari: modifica la informacio de l'usuari logejat.
void CUmodificaUsuari::modificaUsuari(string nomU, string contraU, string correuU, string naixU) {
	Videoconsola& vid = Videoconsola::getInstance();
	vid.refrescaUsuari(nomU, contraU, correuU, naixU); //Modificar l'usuari logejat a la videoconsola
}