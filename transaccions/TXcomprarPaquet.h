#pragma once
#include <iostream>
#include <ctime>
#include "../cercadors/cercadoraElementCompra.h"
#include "../cercadors/cercadoraPaquetVideojocs.h"
#include "../passareles/passarelaCompra.h"
#include "../videoconsola.h"

using namespace std;

class TXcomprarPaquet {
	private:
		
		string nomPaquet;
		string usuari;

	public:
		TXcomprarPaquet(string nom);

		~TXcomprarPaquet();

		void executar();

};