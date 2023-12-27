#pragma once
#include <iostream>
#include <vector>
#include "../passareles/passarelaElementCompra.h"
#include "../cercadors/cercadoraElementCompra.h"
#include "../passareles/passarelaVideojoc.h"
#include "../cercadors/cercadoraVideojoc.h"
#include "../passareles/passarelaConte.h"
#include "../cercadors/cercadoraConte.h"


using namespace std;

class TXconsultarVideojoc {
	private:
		
		string nomV;

		struct res
		{
			string nom, desc, genere, data;
			int qualificacio;
			double preu;
			vector<string> paquets;
		};

		res resultat;

	public:
		TXconsultarVideojoc(string n);

		~TXconsultarVideojoc();

		void executar();

		res obtenirResultat();
};