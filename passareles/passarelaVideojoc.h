#pragma once
#include <iostream>

using namespace std;

class passarelaVideojoc
{
	private:
		
		string nom, dataLlan, genere;
		int qualificacio, minsEstimat;

	public:

		passarelaVideojoc(string n, int q, string data, string g, int mins);

		~passarelaVideojoc();
};

