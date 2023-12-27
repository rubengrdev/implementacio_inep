#pragma once
#include <iostream>
#include <pqxx/pqxx>
#include "../passareles/passarelaPaquetVideojocs.h"

using namespace std;

class cercadoraPaquetVideojocs
{
	private:

		pqxx::connection conn;

	public:
		
		cercadoraPaquetVideojocs();

		~cercadoraPaquetVideojocs();

		passarelaPaquetVideojocs cercaPerNom(string nomP);

};