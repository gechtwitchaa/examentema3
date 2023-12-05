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

