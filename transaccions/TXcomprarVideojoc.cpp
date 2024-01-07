#include "TXcomprarVideojoc.h"

//Constructora
TXcomprarVideojoc::TXcomprarVideojoc(string n) : nom(n) {
    
}

//Destructora
TXcomprarVideojoc::~TXcomprarVideojoc() {
    
}

//executar: Crida per executar
void TXcomprarVideojoc::executar() {
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraVideojoc cercadorVid = cercadoraVideojoc();
    cercadoraUsuari cercadorUs = cercadoraUsuari();

    Videoconsola& consola = Videoconsola::getInstance();
    string usuari = consola.getUsuari(); //Obtenir el nom d'usuari a partir de la videoconsola.

    //Crear les passareles d'elementCompra, videojoc i usuari.
    passarelaVideojoc pvid = cercadorVid.cercaPerNom(nom);
    passarelaElementCompra pel = cercadorEl.cercaPerNom(nom);
    passarelaUsuari pus = cercadorUs.cercaPerSobrenom(usuari);

    //Obtenir data de naixement de l'usuari.
    string dataN = pus.getDataN();

    //Calcular edat de l'usuari.
    char delimiter;
    istringstream data_str(dataN);
    int dia, mes, any;
    data_str >> any >> delimiter >> mes >> delimiter >> dia;
    struct tm dataNaix;
    dataNaix.tm_year = any - 1900; dataNaix.tm_mon = mes - 1; dataNaix.tm_mday = dia;
    dataNaix.tm_hour = 0; dataNaix.tm_min = 0; dataNaix.tm_sec = 0;

    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year + 1900) + "-" + to_string(temps.tm_mon + 1) + "-" + to_string(temps.tm_mday);

    //Obtenir segons de diferencia entre el dia de naixement de l'usuari i el dia actual.
    double segons = difftime(mktime(&temps), mktime(&dataNaix));

    //Obtenir edat
    int anys = (int)segons / 31536000;
    
    //Comprovar si l'usuari te suficient edat per comprar el videojoc.
    if (pvid.getQualificacio() > anys) throw exception("No tens suficient edat.");

    resultat.data = data;

    passarelaCompra compra = passarelaCompra(usuari, nom, data, pel.getPreu());
    try {
        compra.insereix();
    }
    catch (...) {
        //Si es rep una excepcio a la hora d'inserir, vol dir que l'usuari ja ha comprat el videojoc anteriorment.
        throw exception("Ja s'ha comprat el videojoc.");
    }
    
    //Busca tots els paquets on esta el videojoc adquirit
    cercadoraConte con = cercadoraConte();
    vector<passarelaConte> conv = con.cerca(nom);
    for (int i = 0; i < conv.size(); i++) {
        //Busca tots els videojocs que conte el paquet
        vector<passarelaConte> conp = con.cerca(conv[i].getPaquet());
        for (int j = 0; j < conp.size(); j++) {
            if (conp[j].getVideojoc() != nom) {
                bool trobat = false;
                passarelaElementCompra r = cercadorEl.cercaPerNom(conp[j].getVideojoc());
                recomanacio re = recomanacio();
                re.nom = r.getNom();
                re.desc = r.getDescripcio();
                re.preu = r.getPreu();
                for (int jj = 0; !trobat && jj < resultat.recomanats.size(); jj++) trobat = (resultat.recomanats[jj].nom == re.nom);
                //Si el videojoc no es el videojoc aquirit i encara no s'ha afegit a la llista de recomantas, l'afegeix
                if(!trobat) resultat.recomanats.push_back(re);
            }
        }
    }

}

//obteResultat: Crida per retornar el resultat.
TXcomprarVideojoc::res TXcomprarVideojoc::obteResultat() {
    return resultat; //Retorna el resultat.
}
