

#pragma once
#include <array>
#include <string>
#include <regex>
// required <regex> and <algorithm> library for std::transform() function

class HexadecimalConvertor {
public:
    // GLOBAL VARIABLE Min and Max for our 4 digit hexadecimal numbers
    const static int MAX = 65535;
    const static int MIN = -65536;

    // Public Static Procedural Functions- Conversion Decimal<->Hexadecimal

    /**
     * Hexidecimal Char[] to int Decimal value
     * @param hexArray  any char[] will be accepted and cleaned to work.
     * @return the integer value
     */
    static int hexToDecimal(char* hexArray);
    /*

    /**
     * int Decimal value to Hexidecimal Char[]
     * @param value
     * @return char[5] of the +/- & 4 hex digits
     */
    static std::array<char, 5> decimalToHex(int value);


    /**
     * Get a char of an int value
     * @param n 0-15
     * @return 0-9,a-f  otherwise 0;
     */
    static char hexChar(int n);



    static int hexValue(char n);

    // MAX and MIN  defined
    static int hex4digitValueWrap(int n);
    /// <summary>
    /// commented out unitl implemented
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    /*
    if (n > MAX) {
        n = MIN + (n - MAX);
    }
    else if (n < MIN) {
        n = MAX + (n - MIN);
    }
    return n;
    */




    static char* cleanCharHex(char toClean[]);


    int signToInt(char c);
    /*
    int result = 1;
     if (c == '-') {
         result = -1;
     }
     return result;
     */

    std::array<char, 5> makeBlankChar5();


    std::array<char, 5> cleanCharHex(std::array<char, 5> toClean);


};