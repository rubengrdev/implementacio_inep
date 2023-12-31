#include "cercadoraCompra.h"
#include <iostream>
#include <stdexcept>
#include <memory>

cercadoraCompra::cercadoraCompra() {
    // Constructor: Initialize database connection
    dbConnection = std::make_unique<DatabaseConnection>();
    dbConnection->open("path_to_database.db"); // Hypothetical open call
}

cercadoraCompra::~cercadoraCompra() {
    // Destructor: Close database connection if open
    dbConnection->close(); // Hypothetical close call
}

bool cercadoraCompra::findPurchaseByNickname(const std::string& nickname) {
    try {
        pqxx::connection conn(PARAMS);
        pqxx::work txn(conn);
        std::string query = "SELECT * FROM Compra WHERE usuari = " + conn.quote(nickname) + ";";
        pqxx::result r = txn.exec(query);
        txn.commit();

        if (r.empty()) {
            std::cout << "No s'han trobat compres per a l'usuari: " << nickname << std::endl;
            return false;
        }

        for (auto row : r) {
            std::cout << "Compra trobada per a l'usuari: " << nickname << " - "
                      << "Joc: " << row["gameName"].as<std::string>() << ", "
                      << "Preu: " << row["price"].as<double>() << std::endl;
        }
        return true;
    } catch (const std::exception& e) {
        std::cerr << "S'ha produït un error: " << e.what() << std::endl;
        return false;
    }
}
