#include "TXconsultarNovetats.h"

// Constructor: Inicialitza la data de consulta per a les novetats
TXconsultarNovetats::TXconsultarNovetats(string d) : data(d) {
}

// Destructor
TXconsultarNovetats::~TXconsultarNovetats() {
}

// executar: Realitza la consulta de les novetats des de la data especificada
// Pre: data ha estat inicialitzada
// Post: resultat conté les novetats trobades des de la data especificada
void TXconsultarNovetats::executar() {
    cercadoraElementCompra el = cercadoraElementCompra();
    cercadoraVideojoc vid = cercadoraVideojoc();
    cercadoraConte co = cercadoraConte();
    vector<passarelaVideojoc> novetats = vid.cercaNovetats(data);
    for (auto& novetat : novetats) {
        res r = res();
        r.ompleDades(novetat, el, co); // Omple les dades de la resposta amb informació de la novetat
        resultat.push_back(r);
    }
}

// obteResultat: Retorna les novetats trobades
// Pre: 'executar' ha estat cridat
// Post: Retorna un vector amb les novetats des de la data especificada
vector<TXconsultarNovetats::res> TXconsultarNovetats::obteResultat() {
    return resultat;
}
