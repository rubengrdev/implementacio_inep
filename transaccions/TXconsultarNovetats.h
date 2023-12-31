#pragma once
#include <iostream>
#include "../cercadors/cercadoraElementCompra.h"
#include "../cercadors/cercadoraVideojoc.h"
#include "../passareles/passarelaElementCompra.h"
#include "../passareles/passarelaVideojoc.h"
#include "../cercadors/cercadoraConte.h"
#include "../passareles/passarelaConte.h"
#include <vector>

using namespace std;

class TXconsultarNovetats {
	public:

		struct res
		{
			string nom, desc, genere, data;
			int qualificacio;
			double preu;
			vector<string> paquets;
		};

		TXconsultarNovetats(string d);

		~TXconsultarNovetats();

		void executar();

		vector<res> obteResultat();

	private:

		string data;
		vector<res> resultat;
		
};