
#pragma once
#include <string>
#include "Hex4digit.h"

class NumberConverterAccess {
public:
    char* convertToHexChars(short number);
    int convertToInt(char* number);
};