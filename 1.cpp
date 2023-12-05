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

};
int main() {
    Environment env;

    env.addSymbol("x", 10);
    env.addSymbol("y", 20);

    std::cout << "El valor de 'x' es: " << env.getSymbolValue("x") << std::endl;
    std::cout << "El valor de 'y' es: " << env.getSymbolValue("y") << std::endl;

    std::cout << "El valor de 'z' es: " << env.getSymbolValue("z") << std::endl;

    return 0;
}





