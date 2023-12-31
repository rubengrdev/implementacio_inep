#pragma once
#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include "../config.txt"
#include "../passareles/passarelaCompra.h"

using namespace std;

class cercadoraCompra
{
	private:

	public:
		
		cercadoraCompra();

		~cercadoraCompra();

		vector<passarelaCompra> cercaPerUsuari(string u);

		passarelaCompra cercaPerElement(string el);

};