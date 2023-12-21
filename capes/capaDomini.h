#include "../cercadores/cercadoraCompra.h"
#include "../cercadores/cercadoraUsuari.h"
#include "../passareles/passarelaUsuari.h"
#include "../passareles/passarelaCompra.h"
#include "../passareles/passarelaConte.h"
#include "../passareles/passarelaElementCompra.h"
#include "../passareles/passarelaPaquetVideojocs.h"
#include "../passareles/passarelaVideojoc.h"

class capaDomini {
	private:

	public:
		capaDomini();

		~capaDomini();

		void registrarUsuari(string nom, string sobrenom, string contrasenya, string correuE, string dataN);

		pqxx::result totsVideojocs();
};