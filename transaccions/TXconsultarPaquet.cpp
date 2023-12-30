#include "TXconsultarPaquet.h"

TXconsultarPaquet::TXconsultarPaquet(string nom) {
	n = nom;
	resultat = res();
}

TXconsultarPaquet::~TXconsultarPaquet() {

}

void TXconsultarPaquet::executar(){
	cercadoraElementCompra el = cercadoraElementCompra();
	passarelaElementCompra pel = el.cercaPerNom(n);
	cercadoraPaquetVideojocs pa = cercadoraPaquetVideojocs();
	passarelaPaquetVideojocs ppa = pa.cercaPerNom(n);
	cercadoraConte co = cercadoraConte();
	vector<passarelaConte> pco = co.cerca(n);
	resultat.nom = ppa.getNom();
	resultat.desc = pel.getDescripcio();
	resultat.preu = pel.getPreu();
	double total = 0;
	for (int i = 0; i < pco.size(); i++) {
		passarelaElementCompra pvid = el.cercaPerNom(pco[i].getVideojoc());
		resultat.vnoms.push_back(pvid.getNom());
		resultat.vdescs.push_back(pvid.getDescripcio());
		resultat.vpreus.push_back(pvid.getPreu());
		total += pvid.getPreu();
	}
	resultat.estalvi = total - resultat.preu;
}

TXconsultarPaquet::res TXconsultarPaquet::obteResultat() {
	return resultat;
}