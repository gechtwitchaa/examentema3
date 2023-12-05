#include <iostream>
#include <string>
#include <unordered_map>

enum class Type { INT, STRING };

struct Variant {
    Type type;
    int intValue;
    std::string stringValue;


    Variant(int value) : type(Type::INT), intValue(value) {}
    Variant(const char* value) : type(Type::STRING), stringValue(value) {}

 