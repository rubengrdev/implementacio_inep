#include <iostream>

using namespace std;

class TXiniciarSessio {
	private:
		string sobrenom, contrasenya;
		//Resultat
	public:
		TXiniciarSessio(string nom, string cs);

		~TXiniciarSessio();

		void executa();

		//obtenirResultat
};