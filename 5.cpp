#include <iostream>
#include <map>
#include <string>

struct Variant {
    int intValue;
    const char* stringValue;

    Variant() : intValue(0), stringValue(nullptr) {}

    Variant(int value) : intValue(value), stringValue(nullptr) {}

    Variant(const char* value) : intValue(0), stringValue(value) {}
};

class Environment {
private:
    std::map<std::string, Variant> symbolTable;

public:
    void addSymbol(const std::string& symbol, const Variant& value) {
        symbolTable[symbol] = value;
    }

    Variant getSymbolValue(const std::string& symbol) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            return Variant(); // Devuelve un objeto Variant predeterminado
        }
    }
};
