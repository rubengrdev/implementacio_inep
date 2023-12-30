#pragma once
#include <iostream>
#include <pqxx/pqxx>
#include "../passareles/passarelaPaquetVideojocs.h"
#include "../config.txt"

using namespace std;

class cercadoraPaquetVideojocs
{
	private:

	public:
		
		cercadoraPaquetVideojocs();

		~cercadoraPaquetVideojocs();

		passarelaPaquetVideojocs cercaPerNom(string nomP);

};