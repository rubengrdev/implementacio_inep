#include<pqxx/pqxx>
#include<iostream>
#include "../passareles/passarelaUsuari.h"
#include "../config.txt"

class cercadoraUsuari
{
	private:

	public:
		
		cercadoraUsuari();

		~cercadoraUsuari();

		passarelaUsuari cercaPerSobrenom(string sn);

};