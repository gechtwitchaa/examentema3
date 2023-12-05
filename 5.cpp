#include <iostream>
#include <map>
#include <string>

struct Variant {
    int intValue;
    const char* stringValue;

    Variant() : intValue(0), stringValue(nullptr) {}

    Variant(int value) : intValue(value), stringValue(nullptr) {}

    Variant(const char* value) : intValue(0), stringValue(value) {}
};

