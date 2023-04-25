

#pragma once
#include <array>
#include <string>
#include <regex>
#include <cstring>
#include <cstdio>
// required <regex> and <algorithm> library for std::transform() function

class HexadecimalConverter {
public:
    // GLOBAL VARIABLE Max for our 4 digit hexadecimal numbers
    const static int MAX = 65535;
    // GLOBAL VARIABLE Min for our 4 digit hexadecimal numbers
    const static int MIN = -65536;

    // Public Static Procedural Functions- Conversion Decimal<->Hexadecimal
    static int hexToDecimal(char* hexArray);
    static std::array<char, 5> decimalToHex(int value);
    static char hexChar(int n);
    static int hexValue(char n);
    static int hex4digitValueWrap(int n);
    static char* cleanCharHex(char toClean[]);
    int signToInt(char c);
    static std::array<char, 5> makeBlankChar5();
};