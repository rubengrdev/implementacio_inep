#include <pqxx/pqxx>
#include <iostream>
#include "../passareles/passarelaVideojoc.h"

using namespace std;

class cercadoraVideojoc
{
	private:

	public:
		
		cercadoraVideojoc();

		~cercadoraVideojoc();

		passarelaVideojoc cercaPerNom(string n);

};

