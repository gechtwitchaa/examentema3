#include <iostream>
#include <map>
#include <string>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    void addSymbol(const std::string& symbol, int value) {
        symbolTable[symbol] = value;
    }


    int getSymbolValue(const std::string& symbol) {
        if (symbolTable.find(symbol) != symbolTable.end()) {
            return symbolTable[symbol];
        } else {
            std::cerr << "Error: El símbolo '" << symbol << "' no está definido en el entorno." << std::endl;
            return 0;
        }
    }
    
    bool insert(const std::string& symbol, int value) {
        auto it = symbolTable.find(symbol);
        if (it == symbolTable.end()) {
            symbolTable[symbol] = value;
            return true;
        } else {
            std::cerr << "Error: El símbolo '" << symbol << "' ya está definido en el entorno." << std::endl;
            return false;
        }
    }

};

