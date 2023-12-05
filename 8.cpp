#include <iostream>
#include <string>
#include <unordered_map>

enum class Type { INT, STRING };

struct Variant {
    Type type;
    int intValue;
    std::string stringValue;

