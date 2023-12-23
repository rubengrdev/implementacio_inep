#include "../cercadors/cercadoraUsuari.h"
#include "../cercadors/cercadoraCompra.h"
#include "../passareles/passarelaUsuari.h"
#include "../passareles/passarelaCompra.h"
#include "../passareles/passarelaConte.h"
#include "../passareles/passarelaElementCompra.h"
#include "../passareles/passarelaPaquetVideojocs.h"
#include "../passareles/passarelaVideojoc.h"

class TXIniciarSessio {
	private:

	public:
		TXIniciarSessio();

		~TXIniciarSessio();

		void iniciarSessio(string nom, string contrasenya);
		//pqxx::result totsVideojocs();
};