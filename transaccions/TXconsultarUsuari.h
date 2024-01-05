#pragma once
#include <iostream>
#include "../cercadors/cercadoraUsuari.h"
#include "../passareles/passarelaUsuari.h"
#include "../videoconsola.h"
#include <stdexcept>

using namespace std;

class TXconsultarUsuari {
	public:

		struct res {
			string nom, sobrenom, correu, dataN, contrasenya;
		};

		TXconsultarUsuari();

		~TXconsultarUsuari();

		void executar();

		res obteResultat();
	
	private:
		
		res resultat;

};