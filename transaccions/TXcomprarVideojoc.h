#pragma once
#include "../cercadors/cercadoraElementCompra.h"
#include "../cercadors/cercadoraUsuari.h"
#include "../cercadors/cercadoraVideojoc.h"
#include "../videoconsola.h"
#include "../cercadors/cercadoraConte.h"
#include "../passareles/passarelaCompra.h"
#include <iostream>
#include <ctime>

using namespace std;

class TXcomprarVideojoc {
	public:

		struct recomanacio {
			string nom, desc;
			double preu;
		};

		struct res {
			string data;
			vector<recomanacio> recomanats;
		};

		TXcomprarVideojoc(string n);

		~TXcomprarVideojoc();

		void executar();

		res obteResultat();

	private:

		res resultat;
		string nom;

};