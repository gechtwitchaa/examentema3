#include <iostream>
#include <string>
#include <unordered_map>

    enum class Type { INT, STRING }; // Tipos de datos admitidos por Variant

    struct Variant {
        Type type;
        int intValue;
        std::string stringValue;


        Variant(int value) : type(Type::INT), intValue(value) {}
        Variant(const char* value) : type(Type::STRING), stringValue(value) {}


        Variant() : type(Type::INT), intValue(0) {}
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
    abilities.addSymbol("Cura", Variant("Restaura puntos de vida"));
    abilities.addSymbol("Daño Mágico", Variant(30));

    std::cout << "Ataque Furtivo: " << abilities.getSymbol("Ataque Furtivo").stringValue << std::endl;
    std::cout << "Cura: " << abilities.getSymbol("Cura").stringValue << std::endl;
    std::cout << "Daño Mágico: " << abilities.getSymbol("Daño Mágico").intValue << std::endl;
    
    std::cout << "Robar: " << abilities.getSymbol("Robar").stringValue << std::endl;

    return 0;
}