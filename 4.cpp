#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    void addSymbol(const std::string& symbol, int value) {
        if (symbolTable.find(symbol) != symbolTable.end()) {
            if (symbolTable[symbol] != value) {
                throw std::invalid_argument("Intento de insertar un símbolo ya existente con un valor diferente.");
            }
            return;
        }
        symbolTable[symbol] = value;
    }

    std::unique_ptr<int> lookup(const std::string& symbol) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return std::make_unique<int>(it->second);
        } else {
            throw std::out_of_range("El símbolo no está definido en el entorno.");
        }
    }
};

