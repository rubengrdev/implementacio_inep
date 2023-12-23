#include "../cercadors/cercadoraUsuari.h"
#include "../cercadors/cercadoraCompra.h"
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

<<<<<<< HEAD
		void iniciarSessio(string nom, string contrasenya);
=======
>>>>>>> 2354cd233d55582b222f9a67a4ba556e093b764f
		//pqxx::result totsVideojocs();
};