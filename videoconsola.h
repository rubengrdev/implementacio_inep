#pragma once
#include <iostream>

using namespace std;

class Videoconsola {

private:

	bool sessioIniciada;
	string usuari;

	Videoconsola();

public:

	static Videoconsola& getInstance();

	string getUsuari();

	void iniciarSessio(string u);

	void tancarSessio();
};