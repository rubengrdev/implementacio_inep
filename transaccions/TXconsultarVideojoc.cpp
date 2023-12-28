#include "TXconsultarVideojoc.h"

TXconsultarVideojoc::TXconsultarVideojoc(string n) {
	nomV = n;
	resultat = res();
}

TXconsultarVideojoc::~TXconsultarVideojoc() {

}

void TXconsultarVideojoc::executar(){
	cercadoraElementCompra el = cercadoraElementCompra();
	passarelaElementCompra pel = el.cercaPerNom(nomV);
	cercadoraVideojoc vid = cercadoraVideojoc();
	passarelaVideojoc pvid = vid.cercaPerNom(nomV);
	cercadoraConte con = cercadoraConte();
	vector<passarelaConte> pcon = con.cerca(nomV);
	resultat.nom = pel.getNom();
	resultat.desc = pel.getDescripcio();
	resultat.preu = pel.getPreu();
	resultat.genere = pvid.getGenere();
	resultat.data = pvid.getDataLlan();
	resultat.qualificacio = pvid.getQualificacio();
	for (int i = 0; i < pcon.size(); i++) resultat.paquets.push_back(pcon[i].getPaquet());
}

TXconsultarVideojoc::res TXconsultarVideojoc::obteResultat() {
	return resultat;
}