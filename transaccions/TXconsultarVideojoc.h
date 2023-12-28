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
	public:

		struct res
		{
			string nom, desc, genere, data;
			int qualificacio;
			double preu;
			vector<string> paquets;
		};

		TXconsultarVideojoc(string n);

		~TXconsultarVideojoc();

		void executar();

		res obteResultat();

	private:

		string nomV;
		res resultat;
};