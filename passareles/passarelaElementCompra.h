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

		void setDescripcio(string desc);

		void setPreu(double p);

		//Preguntar si cal setter pel tipus

};

