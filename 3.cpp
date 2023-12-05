#include <iostream>
#include <map>
#include <string>
#include <memory>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    void addSymbol(const std::string& symbol, int value) {
        symbolTable[symbol] = value;
    }

    std::unique_ptr<int> lookup(const std::string& symbol) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return std::make_unique<int>(it->second);
        } else {
            return nullptr;
        }
    }
};

int main() {
    Environment env;

    env.addSymbol("x", 10);
    env.addSymbol("y", 20);

    std::unique_ptr<int> valueX = env.lookup("x");
    if (valueX) {
        std::cout << "El valor de 'x' es: " << *valueX << std::endl;
    } else {
        std::cout << "El símbolo 'x' no está definido en el entorno." << std::endl;
    }

    std::unique_ptr<int> valueZ = env.lookup("z");
    if (valueZ) {
        std::cout << "El valor de 'z' es: " << *valueZ << std::endl;
    } else {
        std::cout << "El símbolo 'z' no está definido en el entorno." << std::endl;
    }

    return 0;
}
