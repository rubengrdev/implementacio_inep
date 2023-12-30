#include "TXconsultarPaquets.h"

TXconsultarPaquets::TXconsultarPaquets() {

}

TXconsultarPaquets::~TXconsultarPaquets() {

}

void TXconsultarPaquets::executar(){
	cercadoraElementCompra el = cercadoraElementCompra();
	vector<passarelaElementCompra> pel = el.totsPaquets();
	for (int i = 0; i < pel.size(); i++) {
		cercadoraConte co = cercadoraConte();
		vector<passarelaConte> pco = co.cerca(pel[i].getNom());
		double total = 0;
		for (int j = 0; j < pco.size(); j++) {
			cercadoraElementCompra vid = cercadoraElementCompra();
			passarelaElementCompra pvid = vid.cercaPerNom(pco[j].getVideojoc());
			total += pvid.getPreu();
		}
		res r;
		r.nom = pel[i].getNom();
		r.desc = pel[i].getDescripcio();
		r.preu = pel[i].getPreu();
		r.estalvi = total - r.preu;
		resultat.push_back(r);
	}
}

vector<TXconsultarPaquets::res> TXconsultarPaquets::obteResultat() {
	return resultat;
}