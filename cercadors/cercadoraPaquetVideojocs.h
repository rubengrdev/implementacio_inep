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
		
		//Constructora
		cercadoraPaquetVideojocs();

		//Destructora
		~cercadoraPaquetVideojocs();

		//cercaPerNom: Busca un paquet de videojocs per nom a la base de dades.
		passarelaPaquetVideojocs cercaPerNom(string nomP);

};