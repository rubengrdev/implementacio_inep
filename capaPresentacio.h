#include <iostream>
#include <stdlib.h>
#include <pqxx/pqxx>
#include <vector>
#include <ctime>
#include <cstring>
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
	//funció que retorna SI o NO (true \ false) en el cas de que la data no sigui correcta
	bool comprovarData(string dataN) {
		cout << "Comprovacio de la data:" << endl;

		std::istringstream data_str(dataN);
		bool validessa = false;
		int dia, mes, any;
		char delimiter;

		//extreu valors en cas de format dd - mm - aaaa
		data_str >> dia >> delimiter >> mes >> delimiter >> any;

		if (data_str.eof() && (delimiter == '/') && dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && any > 0)
		{
			validessa = true;  
		}
		//printf("\nvalidessa: %d", validessa);
		//invertirData(dataN);
		return validessa;  
	}
	string invertirData(string dataN) {
		size_t counter;
		char delimiter;
		string new_str;
		counter = dataN.find('/');
		/*
			En el cas de que counter = 2 -> format: dd/mm/aaaa
			En el cas de que counter = 4 -> format: aaaa/mm/dd
		*/
		std::istringstream data_str(dataN);
		
		int dia, mes, any;
		printf("\ncounter = %d",counter);
		if (counter == 4) {
			data_str >> any >> delimiter >> mes >> delimiter >> dia;
		}
		new_str = dia + '/'   + mes +  '/' + any;

		// Devolver la nueva fecha como una cadena
		//return new_data.str();


		//new_data << any << '/' << mes << '/' << dia;
		printf("\n%s\n", new_str);
		return new_str;
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