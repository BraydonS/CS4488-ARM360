
#pragma once
#include <string>
#include "Hex4digit.h"
// Define the NumberConverterAccess class
class NumberConverterAccess {
public:
    // Declare the convertToHexChars method, which takes a short integer as input and returns a char array

    char* convertToHexChars(short number);

    // Declare the convertToInt method, which takes a char array as input and returns an integer

    int convertToInt(char* number);
};