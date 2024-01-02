#include "TXconsultarVideojocsPerEdat.h"

TXconsultarVideojocsPerEdat::TXconsultarVideojocsPerEdat(int e) {
	edat = e;
}

TXconsultarVideojocsPerEdat::~TXconsultarVideojocsPerEdat() {

}

void TXconsultarVideojocsPerEdat::executar(){
	cercadoraVideojoc vid = cercadoraVideojoc();
	vector<passarelaVideojoc> pvid = vid.cercaPerEdat(edat);
	for (int i = 0; i < pvid.size(); i++) {
		cercadoraElementCompra el = cercadoraElementCompra();
		passarelaElementCompra pel = el.cercaPerNom(pvid[i].getNom());
		cercadoraConte con = cercadoraConte();
		vector<passarelaConte> pcon = con.cerca(pvid[i].getNom());
		res r = res();
		r.nom = pel.getNom();
		r.desc = pel.getDescripcio();
		r.preu = pel.getPreu();
		r.genere = pvid[i].getGenere();
		r.data = pvid[i].getDataLlan();
		r.qualificacio = pvid[i].getQualificacio();
		for (int j = 0; j < pcon.size(); j++) r.paquets.push_back(pcon[j].getPaquet());
		resultat.push_back(r);
	}
}

vector<TXconsultarVideojocsPerEdat::res> TXconsultarVideojocsPerEdat::obteResultat() {
	return resultat;
}