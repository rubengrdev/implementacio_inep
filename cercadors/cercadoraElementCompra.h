#pragma once
#include<pqxx/pqxx>
#include<iostream>
#include<vector>
#include "../passareles/passarelaElementCompra.h"
#include "../config.txt"

using namespace std;

class cercadoraElementCompra
{
	private:

	public:
		
		cercadoraElementCompra();

		~cercadoraElementCompra();

		passarelaElementCompra cercaPerNom(string n);

		vector<passarelaElementCompra> totsVideojocs();

		vector<passarelaElementCompra> totsPaquets();

};

