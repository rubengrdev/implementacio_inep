#pragma once
#include <iostream>

using namespace std;

class TXregistrarUsuari {
	private:
		string nom, sobrenom, constrasenya, correuE, dataN;
		//Resultat
	public:
		TXregistrarUsuari(string n, string sn, string c, string correu, string data);

		~TXregistrarUsuari();

		void executar();

		//obtenirResultat
};