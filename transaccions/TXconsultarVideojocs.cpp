#include "TXconsultarVideojocs.h"

TXconsultarVideojocs::TXconsultarVideojocs() {

}

TXconsultarVideojocs::~TXconsultarVideojocs() {

}

void TXconsultarVideojocs::executar(){
	cercadoraElementCompra el = cercadoraElementCompra();
	vector<passarelaElementCompra> pel = el.totsElements();
	for (int i = 0; i < pel.size(); i++) {
		if (pel[i].getTipus() == "videojoc") {
			cercadoraVideojoc vid = cercadoraVideojoc();
			passarelaVideojoc pvid = vid.cercaPerNom(pel[i].getNom());
			cercadoraConte con = cercadoraConte();
			vector<passarelaConte> pcon = con.cerca(pel[i].getNom());
			res r = res();
			r.nom = pel[i].getNom();
			r.desc = pel[i].getDescripcio();
			r.preu = pel[i].getPreu();
			r.genere = pvid.getGenere();
			r.data = pvid.getDataLlan();
			r.qualificacio = pvid.getQualificacio();
			for (int i = 0; i < pcon.size(); i++) r.paquets.push_back(pcon[i].getPaquet());
			resultat.push_back(r);
		}
	}
}

vector<TXconsultarVideojocs::res> TXconsultarVideojocs::obteResultat() {
	return resultat;
}