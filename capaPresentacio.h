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
#include "transaccions/CUmodificaUsuari.h"

using namespace std;

class capaPresentacio {
private:

	capaPresentacio() {

	};

	//Funcio privada per comprovar que el correu te un format correcte
	bool comprovarCorreu(string s) {
		regex pattern(R"(^[w-\.]+@([\w-]+\.)*+[\w-]{2,4}$)");
		return regex_match(s, pattern);
	}

	bool comprovarData(string data) {
		istringstream data_str(data);
		bool validesa = false;
		int dia, mes, any;
		char delimiter;
		//Extreu els valors en el cas de format DD/MM/AAAA
		data_str >> dia >> delimiter >> mes >> delimiter >> any;
		if (data_str.eof() && delimiter == '/' && dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && any > 0) validesa = true;
		return validesa;
	}

	string dataFormatter(string data) {
		size_t counter;
		char delimiter;
		string new_str;
		istringstream data_str(data);
		counter = data.find('/');
		int dia, mes, any;
		if (counter == 2 || counter == 1) {
			data_str >> dia >> delimiter >> mes >> delimiter >> any;
			new_str = to_string(any) + "-" + to_string(mes) + "-" + to_string(dia);
		}
		else if (counter == -1) {
			data_str >> any >> delimiter >> mes >> delimiter >> dia;
			new_str = to_string(dia) + "/" + to_string(mes) + "/" + to_string(any);
		}
		return new_str;
	}

public:

	static capaPresentacio& getInstance();

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