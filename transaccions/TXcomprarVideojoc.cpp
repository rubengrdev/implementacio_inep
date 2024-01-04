#include "TXcomprarVideojoc.h"

TXcomprarVideojoc::TXcomprarVideojoc(string n) : nom(n) {
    // Constructor
}

TXcomprarVideojoc::~TXcomprarVideojoc() {
    // Destructor
}

void TXcomprarVideojoc::executar() {
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraVideojoc cercadorVid = cercadoraVideojoc();
    cercadoraUsuari cercadorUs = cercadoraUsuari();

    Videoconsola& consola = Videoconsola::getInstance();
    string usuari = consola.getUsuari();

    passarelaVideojoc pvid = cercadorVid.cercaPerNom(nom);
    passarelaElementCompra pel = cercadorEl.cercaPerNom(nom);
    passarelaUsuari pus = cercadorUs.cercaPerSobrenom(usuari);

    string dataN = pus.getDataN();

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

    double segons = difftime(mktime(&temps), mktime(&dataNaix));

    int anys = (int)segons / 31536000;

    if (pvid.getQualificacio() > anys) throw exception("No tens suficient edat.");

    resultat.data = data;

    passarelaCompra compra = passarelaCompra(usuari, nom, data, pel.getPreu());
    try {
        compra.insereix();
    }
    catch (...) {
        throw exception("Ja s'ha comprat el videojoc.");
    }
    

    cercadoraConte con = cercadoraConte();
    vector<passarelaConte> conv = con.cerca(nom);

    for (int i = 0; i < conv.size(); i++) {
        vector<passarelaConte> conp = con.cerca(conv[i].getPaquet());
        for (int j = 0; j < conp.size(); j++) {
            if (conp[j].getVideojoc() != nom) {
                bool trobat = false;
                passarelaElementCompra r = cercadorEl.cercaPerNom(conp[j].getVideojoc());
                recomanacio re = recomanacio();
                re.nom = r.getNom();
                re.desc = r.getDescripcio();
                re.preu = r.getPreu();
                for (int jj = 0; !trobat && jj < resultat.recomanats.size(); jj++) {
                    trobat = (resultat.recomanats[jj].nom == re.nom);
                }
                if(!trobat) resultat.recomanats.push_back(re);
            }
        }
    }

}

TXcomprarVideojoc::res TXcomprarVideojoc::obteResultat() {
    return resultat;
}
