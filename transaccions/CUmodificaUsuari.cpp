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
	passarelaUsuari* pus = vid.getUsuari(); //obte el sobrenom de l'usuari a partir de la videoconsola
	pus -> setNom(nomU);
	pus -> setContrasenya(contraU);
	pus -> setCorreu(correuU);
	pus -> setDataN(naixU);
	pus -> modifica(); //envia l'ordre per actualitzar la BD amb els nous valors
}