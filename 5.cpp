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

int main() {
    Environment env;

    Variant varInt(10);
    Variant varStr("Hola, Mundo!");

    env.addSymbol("numero", varInt);
    env.addSymbol("saludo", varStr);

    Variant valueNum = env.getSymbolValue("numero");
    std::cout << "El valor del número es: " << valueNum.intValue << std::endl;

    Variant valueStr = env.getSymbolValue("saludo");
    std::cout << "El saludo es: " << valueStr.stringValue << std::endl;

    Variant valueInvalid = env.getSymbolValue("inexistente");
    std::cout << "El valor del símbolo inexistente es: " << valueInvalid.stringValue << std::endl;

    return 0;
}
