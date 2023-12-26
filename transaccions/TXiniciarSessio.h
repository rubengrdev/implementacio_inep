#pragma once
#include <iostream>

using namespace std;

class TXiniciarSessio {
	private:
		string sobrenom, contrasenya;
	public:

		TXiniciarSessio(string sn, string cs);

		~TXiniciarSessio();

		void executar();

		//obtenirResultat

};