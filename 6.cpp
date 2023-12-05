#include <iostream>
#include <map>
#include <string>

struct Variant {
};

class Environment {
private:
    std::map<std::string, Variant> symbolTable;

public:
    void removeSymbol(const std::string& symbol) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            symbolTable.erase(it);
            std::cout << "Símbolo '" << symbol << "' eliminado." << std::endl;
        } else {
            std::cout << "No se encontró el símbolo '" << symbol << "'." << std::endl;
        }
    }

