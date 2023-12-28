#pragma once
#include <iostream>

using namespace std;

class Videoconsola {

private:

	bool sessioIniciada;
	string usuari;

	Videoconsola() {
		sessioIniciada = false;
	}

public:

	static Videoconsola& getInstance() {
		static Videoconsola instance;
		return instance;
	}

	string getUsuari();

	void iniciarSessio(string u);

	void tancarSessio();
};