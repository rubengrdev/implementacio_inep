#include<pqxx/pqxx>
#include<iostream>
#include "../passareles/passarelaConte.h"
#include <vector>

class cercadoraConte
{
	private:

	public:
		
		cercadoraConte();

		~cercadoraConte();

		vector<passarelaConte> cerca(string n);
};

