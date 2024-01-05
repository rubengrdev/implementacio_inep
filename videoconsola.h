#pragma once
#include <iostream>

using namespace std;

class Videoconsola {

private:

	bool sessioIniciada;
	string usuari;

	//Constructora privada
	Videoconsola();

public:

	//Operacio per rebre la instancia de videoconsola 
	static Videoconsola& getInstance();

	//Getter
	string getUsuari();

	//Setters
	void iniciarSessio(string u);

	void tancarSessio();
};