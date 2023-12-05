#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>

class Environment {
private:
    std::map<std::string, int> symbolTable;

