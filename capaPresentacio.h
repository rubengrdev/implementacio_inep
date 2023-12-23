#include <iostream>
#include <stdlib.h>
#include "transaccions/capaDomini.h"
<<<<<<< HEAD
#include "transaccions/TXIniciarSessio.h"
=======
>>>>>>> 2354cd233d55582b222f9a67a4ba556e093b764f

using namespace std;

class capaPresentacio {
private:

	capaDomini cDom;
<<<<<<< HEAD
	TXIniciarSessio txIniSessio;
=======
>>>>>>> 2354cd233d55582b222f9a67a4ba556e093b764f

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