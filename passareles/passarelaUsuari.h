#pragma once
#include<pqxx/pqxx>
#include<iostream>
#include "../config.txt"

using namespace std;

class passarelaUsuari
{
	private:

		string nom, sobrenom, contrasenya, correuE, dataN;

	public:
		
		passarelaUsuari(string n, string sn, string c, string cE, string dN);

		~passarelaUsuari();

		string getNom();

		string getSobrenom();

		string getContrasenya();

		string getCorreu();

		string getDataN();

		void setNom(string n);

		void setContrasenya(string c);

		void setCorreu(string cE);

		void setDataN(string dN);

		void insereix();

		void modifica();

		void esborra();
};

