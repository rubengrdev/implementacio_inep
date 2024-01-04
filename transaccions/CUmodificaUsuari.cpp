#include "CUmodificaUsuari.h"

CUmodificaUsuari::CUmodificaUsuari() {

}

CUmodificaUsuari:: ~CUmodificaUsuari() {

}

TXconsultarUsuari::res CUmodificaUsuari::consultaUsuari() {
	TXconsultarUsuari op = TXconsultarUsuari();
	op.executar();
	TXconsultarUsuari::res r = op.obteResultat();
	return r;
}

void CUmodificaUsuari::modificaUsuari(string nomU, string contraU, string correuU, string naixU) {
	Videoconsola& vid = Videoconsola::getInstance();
	string u = vid.getUsuari();
	cercadoraUsuari us = cercadoraUsuari();
	passarelaUsuari pus = us.cercaPerSobrenom(u);
	pus.setNom(nomU);
	pus.setContrasenya(contraU);
	pus.setCorreu(correuU);
	pus.setDataN(naixU);
	pus.modifica();
}