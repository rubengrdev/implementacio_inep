#include "cercadoraUsuari.h"
#include "cercadoraCompra.h"
#include "passarelaUsuari.h"
#include "passarelaCompra.h"
#include "passarelaConte.h"
#include "passarelaElementCompra.h"
#include "passarelaPaquetVideojocs.h"
#include "passarelaVideojoc.h"

class capaDomini {
	private:

	public:
		capaDomini();

		~capaDomini();

		void registrarUsuari(string nom, string sobrenom, string contrasenya, string correuE, string dataN);

		pqxx::result totsVideojocs();
};