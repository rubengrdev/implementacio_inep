#include "cercadoraConte.h"
#include "../passareles/passarelaConte.h"
#include <string>
#include <vector>

cercadoraConte::cercadoraConte() {
    // Constructor
}

cercadoraConte::~cercadoraConte() {
    // Destructor
}

std::vector<passarelaConte> cercadoraConte::cerca(std::string n) {
    std::vector<passarelaConte> res;
    string comanda = "SELECT * FROM public.\"Conte\" WHERE paquet = '" + n + "' OR videojoc = '" + n + "';";
    try {
        pqxx::connection conn(PARAMS);
        pqxx::work txn(conn);
        pqxx::result q = txn.exec(comanda);
        txn.commit();

        for (auto row : q) {
            res.emplace_back(row["videojoc"].as<std::string>(), row["paquet"].as<std::string>());
        }
    } catch (const std::exception& e) {
        std::cerr << "S'ha produït una excepció: " << e.what() << std::endl;
        throw;
    }
    return res;
}
