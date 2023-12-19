#include "cercadoraUsuari.h"
#include "passarelaUsuari.h"
#include "cercadoraCompra.h"
#include "passarelaCompra.h"

class capaDomini {
	private:

	public:
		capaDomini();

		~capaDomini();

		void registrarUsuari(string nom, string sobrenom, string contrasenya, string correuE, string dataN);
};