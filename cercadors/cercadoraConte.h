#include<pqxx/pqxx>
#include<iostream>
#include "../passareles/passarelaConte.h"
#include <vector>

class cercadoraConte
{
	private:
		
		pqxx::connection conn;

	public:
		
		cercadoraConte();

		~cercadoraConte();

		vector<passarelaConte> cercaPerVideojoc(string nomV);

		vector<passarelaConte> cercaPerPaquet(string nomP);
};

