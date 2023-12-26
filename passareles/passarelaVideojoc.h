#pragma once
#include <iostream>

using namespace std;

class passarelaVideojoc
{
	private:
		
		string nom, dataLlan, genere;
		int qualificacio, minsEstimat;

	public:

		passarelaVideojoc(string n, int q, string data, string g, int mins);

		~passarelaVideojoc();

		string getNom();

		string getDataLlan();

		string getGenere();

		int getQualificacio();

		int getMinsEstimat();

		//No fan falta setters ni operacions sobre la BD ja que l'usuari no pot modificar el cataleg
};

