#include <iostream>
#include <pqxx/pqxx>
#include <stdlib.h>
#include "capaPresentacio.h"

using namespace std;

int main() {
	int op;
	bool sessioIniciada = false; 
	capaPresentacio& cP = capaPresentacio::getInstance();
	while (true) {
		if (!sessioIniciada) {
			while (!sessioIniciada) {
				cout << "*********************" << endl << "    Menu Principal" << endl << "*********************" << endl;
				cout << "1. Iniciar sessio" << endl;
				cout << "2. Registrar usuari" << endl;
				cout << "3. Sortir" << endl;
				cout << "Opcio: ";
				cin >> op;
				system("CLS");
				switch (op) {
				case 1:
					sessioIniciada = cP.iniciarSessioPres();
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
		cout << "*********************" << endl << "    Menu Principal" << endl << "*********************" << endl;
		cout << "1. Gestionar usuari" << endl;
		cout << "2. Gestionar compres" << endl;
		cout << "3. Consultar" << endl;
		cout << "4. Tancar sessio" << endl;
		cout << "5. Sortir" << endl;
		cout << "Opcio: ";
		cin >> op;
		system("CLS");
		switch (op) {
			case 1:
				cout << endl << "--- GESTIONAR USUARI ---" << endl;
				cout << "1. Consultar usuari" << endl;
				cout << "2. Modificar usuari" << endl;
				cout << "3. Esborrar usuari" << endl;
				cout << "4. Tornar" << endl;
				cout << "Opcio: ";
				cin >> op;
				system("CLS");
				switch (op) {
					case 1:
						cP.consultarUsuariPres();
						break;
					case 2:
						cP.modificarUsuariPres();
						break;
					case 3:
						sessioIniciada = cP.esborrarUsuariPres();
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
				system("CLS");
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
				system("CLS");
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
						break;
					case 7:
						break;
					default:
						cout << "Selecciona una opcio valida amb les tecles de l'1 al 7" << endl;
						break;
				}
				break;
			case 4:
				sessioIniciada = cP.tancarSessioPres();
				break;
			case 5:
				return 0;
			default:
				cout << "Selecciona una opcio vàlida amb les tecles de l'1 al 5" << endl;
		}
	}
	return 0;
}