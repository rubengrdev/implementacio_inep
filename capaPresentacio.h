#include <iostream>
#include <stdlib.h>
#include <pqxx/pqxx>
#include <vector>
#include <ctime>
#include <regex>
#include "transaccions/TXcomprarPaquet.h"
#include "transaccions/TXcomprarVideojoc.h"
#include "transaccions/TXconsultarCompres.h"
#include "transaccions/TXconsultarNovetats.h"
#include "transaccions/TXconsultarPaquet.h"
#include "transaccions/TXconsultarPaquets.h"
#include "transaccions/TXconsultarUsuari.h"
#include "transaccions/TXconsultarVideojoc.h"
#include "transaccions/TXconsultarVideojocs.h"
#include "transaccions/TXconsultarVideojocsPerEdat.h"
#include "transaccions/TXesborrarUsuari.h"
#include "transaccions/TXiniciarSessio.h"
#include "transaccions/TXregistrarUsuari.h"
#include "transaccions/TXtancarSessio.h"

using namespace std;

class capaPresentacio {
private:

	capaPresentacio() {

	};

	bool comprovarCorreu(string s) {
		regex pattern(R"(^[w-\.]+@([\w-]+\.)+[\w-]{2,4}$)");
		return regex_match(s, pattern);
	}

public:

	static capaPresentacio& getInstance() {
		static capaPresentacio instance;
		return instance;
	}

	~capaPresentacio();

	bool iniciarSessioPres();

	bool tancarSessioPres();

	void registrarUsuariPres();

	void consultarUsuariPres();

	void modificarUsuariPres();

	bool esborrarUsuariPres();

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