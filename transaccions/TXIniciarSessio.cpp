#include "TXIniciarSessio.h"

TXIniciarSessio::TXIniciarSessio() {

}

TXIniciarSessio::~TXIniciarSessio() {

}
//aixó segons el diagrama de classes no hauria d'estar aquí, hauria de ser a la transacció TXIniciarSessio, TO DO...
void TXIniciarSessio::iniciarSessio(string nom, string contrasenya){
	//cercadoraUsuari usuari(nom, contrasenya);
	//usuari.cercaUsuari();
	cout << "He accedit a la transacció de Inicia Sessio!" << endl;
}
