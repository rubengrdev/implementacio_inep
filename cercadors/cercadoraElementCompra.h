#pragma once
#include<pqxx/pqxx>
#include<iostream>
#include<vector>
#include "../passareles/passarelaElementCompra.h"

using namespace std;

class cercadoraElementCompra
{
	private:

	public:
		
		cercadoraElementCompra();

		~cercadoraElementCompra();

		passarelaElementCompra cercaPerNom(string n);

		vector<passarelaElementCompra> totsElements();

};

