#pragma once
#include<iostream>

using namespace std;

class passarelaConte
{
	private:

		string videojoc, paquet;

	public:

		passarelaConte(string v, string p);

		~passarelaConte();

		string getVideojoc();

		string getPaquet();

		//No fan falta setters ni operacions sobre la BD ja que l'usuari no pot modificar el cataleg

};

