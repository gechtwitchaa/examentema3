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

