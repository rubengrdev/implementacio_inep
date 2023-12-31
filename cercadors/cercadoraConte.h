#pragma once
#include<pqxx/pqxx>
#include<iostream>
#include "../passareles/passarelaConte.h"
#include "../config.txt"
#include <vector>

class cercadoraConte
{
	private:

	public:
		
		cercadoraConte();

		~cercadoraConte();

		vector<passarelaConte> cerca(string n);
};