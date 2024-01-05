#include "TXconsultarVideojoc.h"

//Constructora
TXconsultarVideojoc::TXconsultarVideojoc(string n) {
	nomV = n;
	resultat = res();
}

//Destructora
TXconsultarVideojoc::~TXconsultarVideojoc() {

}

//executar: Crida per executar.
void TXconsultarVideojoc::executar(){
	//Crea les passareles d'elementCompra, videojoc i conte(per saber els paquets on es pot trobar el videojoc).
	cercadoraElementCompra el = cercadoraElementCompra();
	cercadoraVideojoc vid = cercadoraVideojoc();
	cercadoraConte con = cercadoraConte();
	passarelaElementCompra pel = el.cercaPerNom(nomV);
	passarelaVideojoc pvid = vid.cercaPerNom(nomV);
	vector<passarelaConte> pcon = con.cerca(nomV);

	//Emplena el resultat amb la informacio del videojoc.
	resultat.nom = pel.getNom();
	resultat.desc = pel.getDescripcio();
	resultat.preu = pel.getPreu();
	resultat.genere = pvid.getGenere();
	resultat.data = pvid.getDataLlan();
	resultat.qualificacio = pvid.getQualificacio();
	for (int i = 0; i < pcon.size(); i++) resultat.paquets.push_back(pcon[i].getPaquet());
}

//obteResultat: Crida per retornar el resultat.
TXconsultarVideojoc::res TXconsultarVideojoc::obteResultat() {
	return resultat; //Retorna el resultat.
}