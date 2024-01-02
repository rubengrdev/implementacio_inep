#pragma once
#include <pqxx/pqxx>
#include <iostream>
#include "../config.txt"

using namespace std;

class passarelaCompra
{
	private:

		string usuari, element, data;
		double preuPagat;
	
	public:

		passarelaCompra(string u, string e, string d, double p);

		~passarelaCompra();

		string getUsuari();

		string getElement();

		string getData();

		double getPreu();

		void insereix();

		void modifica();

		void esborra();

};

