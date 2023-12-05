#include <iostream>
#include <unordered_map>
#include <string>

enum class Type { INT, STRING };

struct Variant {
    Type type;
    union {
        int intValue;
        const char* stringValue;
    };

    Variant() : type(Type::INT), intValue(0) {}

    Variant(int value) : type(Type::INT), intValue(value) {}

    Variant(const char* value) : type(Type::STRING), stringValue(value) {}


};

class Environment {
    std::unordered_map<std::string, Variant> symbols;

public:
    void addSymbol(const std::string& name, const Variant& value) {
        symbols[name] = value;
    }

    Variant getSymbol(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        }
        return Variant("No existe esa habilidad");
    }

};

int main() {
    Environment abilities;

    abilities.addSymbol("Ataque Furtivo", Variant("Realiza un ataque sigiloso"));
    abilities.addSymbol("Cura", Variant("cura puntos de vida"));

    Variant ability1 = abilities.getSymbol("Ataque Furtivo");
    Variant ability2 = abilities.getSymbol("Cura");

 