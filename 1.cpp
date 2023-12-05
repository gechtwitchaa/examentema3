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
            




