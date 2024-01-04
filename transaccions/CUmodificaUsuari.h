#include <iostream>
#include "../transaccions/TXconsultarUsuari.h"
#include "../cercadors/cercadoraUsuari.h"
#include "../passareles/passarelaUsuari.h"
#include "../videoconsola.h"

using namespace std;

class CUmodificaUsuari {
	public:

		CUmodificaUsuari();

		~CUmodificaUsuari();

		TXconsultarUsuari::res consultaUsuari();

		void modificaUsuari(string nomU, string contraU, string correuU, string naixU);

	private:

	
};