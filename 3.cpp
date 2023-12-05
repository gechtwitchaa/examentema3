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

  