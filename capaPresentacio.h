#include <iostream>
#include <stdlib.h>
#include "transaccions/capaDomini.h"
#include "transaccions/TXIniciarSessio.h"

using namespace std;

class capaPresentacio {
private:

	capaDomini cDom;
	TXIniciarSessio txIniSessio;

public:
	capaPresentacio();

	~capaPresentacio();

	void iniciarSessioPres();

	void tancarSessioPres();

	void registrarUsuariPres();

	void consultarUsuariPres();

	void modificarUsuariPres();

	void esborrarUsuariPres();

	void comprarVideojocPres();

	void comprarPaquetPres();

	void consultarCompresPres();

	void consultarVideojocPres();

	void consultarVideojocsPres();

	void consultarVideojocsEdatPres();

	void consultarNovetatsPres();

	void consultarPaquetPres();

	void consultarPaquetsPres();

};