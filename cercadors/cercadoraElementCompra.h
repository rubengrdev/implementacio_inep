#include<pqxx/pqxx>
#include<iostream>
#include "../passareles/passarelaElementCompra.h"

class cercadoraElementCompra
{
	private:

		pqxx::connection conn;

	public:
		
		cercadoraElementCompra();

		~cercadoraElementCompra();

		passarelaElementCompra cercaPerNom(string n);

};

