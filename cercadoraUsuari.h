#include<pqxx/pqxx>
#include<iostream>
#include "passarelaUsuari.h"

class cercadoraUsuari
{
	private:

	public:
		
		cercadoraUsuari();

		~cercadoraUsuari();

		passarelaUsuari cercaUsuari(string sobrenomU);
};

