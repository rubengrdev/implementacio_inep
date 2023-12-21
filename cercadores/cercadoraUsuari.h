#include<pqxx/pqxx>
#include<iostream>
<<<<<<< HEAD:cercadores/cercadoraUsuari.h
#include "../passareles/passarelaUsuari.h"
=======
#include "passareles/passarelaUsuari.h"
>>>>>>> 5a95daf21fd6fbbd077a1b75075f8bc767c02a5d:cercadoraUsuari.h

class cercadoraUsuari
{
	private:

	public:
		
		cercadoraUsuari();

		~cercadoraUsuari();

		passarelaUsuari cercaUsuari(string sobrenomU);
};

