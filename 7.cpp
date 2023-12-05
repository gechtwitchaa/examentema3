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

