#pragma once
#include <iostream>
#include "../passareles/passarelaUsuari.h"

using namespace std;

class TXregistrarUsuari {
	private:
		string nom, sobrenom, constrasenya, correuE, dataN;
		//Resultat
	public:
		TXregistrarUsuari(string n, string sn, string c, string correu, string data);

		~TXregistrarUsuari();

		void executar();
		
		bool obteResultat();
};