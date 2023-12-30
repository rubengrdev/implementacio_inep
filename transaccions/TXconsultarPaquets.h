#pragma once
#include <iostream>
#include <vector>
#include "../cercadors/cercadoraElementCompra.h"
#include "../passareles/passarelaElementCompra.h"
#include "../cercadors/cercadoraConte.h"
#include "../passareles/passarelaConte.h"
#include "../cercadors/cercadoraVideojoc.h"
#include "../passareles/passarelaVideojoc.h"

using namespace std;

class TXconsultarPaquets {
	public:

		struct res {
			string nom, desc;
			double preu, estalvi;
		};

		TXconsultarPaquets();

		~TXconsultarPaquets();

		void executar();

		vector<res> obteResultat();

	private:
		
		vector<res> resultat;

};