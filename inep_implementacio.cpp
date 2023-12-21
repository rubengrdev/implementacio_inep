#include <iostream>
#include <pqxx/pqxx>
#include "capes/capaPresentacio.h"

using namespace std;

bool sessioIniciada = false;
string sobrenom;

int main() {
	int op;
	capaPresentacio cP = capaPresentacio();
	while (true) {
		if (!sessioIniciada) {
			while (!sessioIniciada) {
				cout << "*********************" << endl << "    Menu Principal" << endl << "*********************" << endl;
				cout << "1. Iniciar sessio" << endl;
				cout << "2. Registrar usuari" << endl;
				cout << "3. Sortir" << endl;
				cout << "Opcio: ";
				cin >> op;
				switch (op) {
				case 1:
					cP.iniciarSessioPres();
					break;
				case 2:
					cP.registrarUsuariPres();
					break;
				case 3:
					return 0;
				default:
					cout << "Selecciona una opcio valida amb les tecles de l'1 al 3" << endl;
				}
			}
		}
		cout << "*********************" << endl << "Menu Principal" << endl << "*********************" << endl;
		cout << "1. Gestionar usuari" << endl;
		cout << "2. Gestionar compres" << endl;
		cout << "3. Consultar" << endl;
		cout << "4. Tancar sessio" << endl;
		cout << "5. Sortir" << endl;
		cout << "Opcio: ";
		cin >> op;
		switch (op) {
		case 1:
			cout << endl << "--- GESTIONAR USUARI ---" << endl;
			cout << "1. Consultar usuari" << endl;
			cout << "2. Modificar usuari" << endl;
			cout << "3. Esborrar usuari" << endl;
			cout << "4. Tornar" << endl;
			cout << "Opcio: ";
			cin >> op;
			switch (op) {
			case 1:
				cP.consultarUsuariPres();
				break;
			case 2:
				cP.modificarUsuariPres();
				break;
			case 3:
				cP.esborrarUsuariPres();
				break;
			case 4:
				break;
			default:
				cout << "Selecciona una opcio valida amb les tecles de l'1 al 4" << endl;
				break;
			}
			break;
		case 2:
			cout << endl << "--- GESTIO DE COMPRES ---" << endl;
			cout << "1. Comprar videojoc" << endl;
			cout << "2. Comprar paquet videojocs" << endl;
			cout << "3. Consultar compres" << endl;
			cout << "4. Tornar" << endl;
			cout << "Opcio: ";
			cin >> op;
			switch (op) {
			case 1:
				cP.comprarVideojocPres();
				break;
			case 2:
				cP.comprarPaquetPres();
				break;
			case 3:
				cP.consultarCompresPres();
				break;
			case 4:
				break;
			default:
				cout << "Selecciona una opcio valida amb les tecles de l'1 al 4" << endl;
				break;
			}
			break;
		case 3:
			cout << endl << "--- CONSULTES DE VIDEOJOCS ---" << endl;
			cout << "1. Consultar videojoc" << endl;
			cout << "2. Consultar videojocs" << endl;
			cout << "3. Consultar videojocs per edat" << endl;
			cout << "4. Consultar novetats videojocs" << endl;
			cout << "5. Consultar paquet videojocs" << endl;
			cout << "6. Consultar paquets videojocs" << endl;
			cout << "7. Tornar" << endl;
			cout << "Opcio: ";
			cin >> op;
			switch (op) {
			case 1:
				cP.consultarVideojocPres();
				break;
			case 2:
				cP.consultarVideojocsPres();
				break;
			case 3:
				cP.consultarVideojocsEdatPres();
				break;
			case 4:
				cP.consultarNovetatsPres();
				break;
			case 5:
				cP.consultarPaquetPres();
				break;
			case 6:
				cP.consultarPaquetsPres();
			case 7:
				break;
			default:
				cout << "Selecciona una opcio valida amb les tecles de l'1 al 7" << endl;
				break;
			}
			break;
		case 4:
			cP.tancarSessioPres();
			break;
		case 5:
			return 0;
		default:
<<<<<<< HEAD
			cout << "Selecciona una opcio vï¿½lida amb les tecles de l'1 al 5" << endl;
=======
			cout << "Selecciona una opcio vàlida amb les tecles de l'1 al 5" << endl;
>>>>>>> 5a95daf21fd6fbbd077a1b75075f8bc767c02a5d
		}
	}
	return 0;
}

/*int main() {
	try {
		pqxx::connection conn("dbname=postgres user=postgres password=1234 hostaddr = 127.0.0.1 port = 5432");
		if (conn.is_open()) {
			cout << "Connexio exitosa amb la base de dades." << endl << endl;
		}
		else {
			cerr << "Error de connexio amb la base de dades." << endl << endl;
			return 1;
		}
		// Per realitzar una consulta...
		// 1.- es crea un pqxx::work amb la connexiï¿½ que hem creat
		pqxx::work txn(conn);
		// 2.- s'executa una comanda en SQL que correspon a la consulta
		pqxx::result result = txn.exec("SELECT * FROM musics");
		// si a l'executar us dï¿½na el missatge que no troba la taula, potser necessiteu posar :
		// "SELECT * FROM public.musics" o ""SELECT * FROM public.\"MUSICS\"
		// podeu confirmar la sintaxi de la comanda en el pgAdmin, sobre la taula escollir la opciï¿½ Scripts\SELECT Script
		// Per mostrar el resultat de la consulta, hem de recï¿½rrer les files (primer for) ...
		cout << "--------------------------------------------" << endl;
		cout << "Opcio de recorrer el resultat amb dos loops" << endl;
		cout << "-------------------------------------------" << endl;
		for (const auto& row : result) {
			// ... i per cada fila, es recorren els camps (l'ordre ï¿½s el que es veu a les columnes al pgAdmin
			for (const auto& field : row) {
				cout << field.name() << ": " << field.c_str() << "\t";
			}
			cout << endl;
		}
		// tambï¿½ es poden recï¿½rrer els resultats com si fosin una matriu de files i columnes(amb indexos comenï¿½ant per 0)
		cout << "---------------------------------------------" << endl;
		cout << "Opcio de recorrer el resultat com una matriu" << endl;
		cout << "---------------------------------------------" << endl;
		for (size_t i = 0; i < result.size(); ++i) {
			for (size_t j = 0; j < result[i].size(); ++j) {
				cout << result[i][j].name() << ": " << result[i][j].c_str() << "\t";
			}
			cout << endl;
		}
		// Finalment, s'ha de confirmar la transacciï¿½n
		txn.commit();
		// La connexiï¿½ es tanca automï¿½ticament al sortir del try
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}*/
