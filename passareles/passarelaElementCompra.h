#pragma once
#include<iostream>

using namespace std;

class passarelaElementCompra
{
	private:

		string nom, descripcio, tipus;
		double preu;

	public:

		passarelaElementCompra(string n, string desc, double p, string t);

		~passarelaElementCompra();

		string getNom();

		string getDescripcio();

		double getPreu();

		string getTipus();

		//No fan falta setters ni operacions sobre la BD ja que l'usuari no pot modificar el cataleg

};

