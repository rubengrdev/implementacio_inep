#pragma once
#include <pqxx/pqxx>
#include <iostream>
#include "../passareles/passarelaVideojoc.h"
#include "../config.txt"

using namespace std;

class cercadoraVideojoc
{
	private:

	public:
		
		cercadoraVideojoc();

		~cercadoraVideojoc();

		passarelaVideojoc cercaPerNom(string n);
		
		vector<passarelaVideojoc> cercaNovetats(string d);

};

