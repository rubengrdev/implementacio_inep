#pragma once
#include<pqxx/pqxx>
#include<iostream>

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

		void setSobrenom(string sn);

		void setContrasenya(string c);

		void setCorreu(string cE);

		void setDataN(string dN);

		void insereix();

		void modifica();

		void esborra();
};

