#pragma once
#include <iostream>
#include "passareles/passarelaUsuari.h"

using namespace std;

class Videoconsola {

private:

	bool sessioIniciada;
	//string usuari;
	passarelaUsuari* pus;

	//Constructora privada
	Videoconsola();

public:

	//Operacio per rebre la instancia de videoconsola 
	static Videoconsola& getInstance();

	//Getter
	string getUsuari();

	//Setters
	void iniciarSessio(passarelaUsuari pus);

	void tancarSessio();
};