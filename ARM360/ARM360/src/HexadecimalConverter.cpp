#include <cstring>
#include <cstdio>
#include "stdafx.h"
#include "HexadecimalConverter.h"
#include <array>
#include <string>


// MAX and MIN are defined using LONG_MAX and LONG_MIN respectively
#define MAX LONG_MAX
#define MIN LONG_MIN


    // Public Static Procedural Functions- Conversion Decimal<->Hexadecimal

    /**
     * Hexidecimal Char[] to int Decimal value
     * @param hexArray  any char[] will be accepted and cleaned to work.
     * @return the integer value
     */
int HexadecimalConverter::hexToDecimal(char* hexArray) {
    hexArray = HexadecimalConverter::cleanCharHex(hexArray); // input scrub
    int index = strlen(hexArray) - 1;
    int power = 1;
    int result = 0;

    // check for the negative sign.
    bool isNegative = (hexArray[0] == '-');

    // Hexadecimal conversion algorithm
    while (index > 0) {
        result = result + (hexValue(hexArray[index]) * power);
        index = index - 1;
        power = power * 16;
    }

    // If negative flip
    if (isNegative) {
        result = result * -1;

        // Special case for the min, due to 2's compliment trickery and Java number types.
        if (result == 0) {
            result = MIN;
        }
    }

    return result;
}

/**
 * int Decimal value to Hexidecimal Char[]
 * @param value
 * @return char[5] of the +/- & 4 hex digits
 */
std::array<char, 5> decimalToHex(int value) {
    value = hex4digitValueWrap(value);
    std::array<char, 5> output = makeBlankChar5();
    int index = output.size() - 1;
    int remainder;
    bool isNegative = (value < 0);


    if (isNegative) {
        output[0] = '-';
        value = value * -1;
    }

    while (index > 0) {
        remainder = value % 16;
        value = value / 16;
        output[index] = hexChar(remainder);
        index = index - 1;
    }


    return output;
}


/**
 * Get a char of an int value
 * @param n 0-15
 * @return 0-9,a-f  otherwise 0;
 */
char hexChar(int n) {
    char result = '0';
    switch (n) {
    case 0: result = '0';
        break;
    case 1:
        result = '1';
        break;
    case 2:
        result = '2';
        break;
    case 3:
        result = '3';
        break;
    case 4:
        result = '4';
        break;
    case 5:
        result = '5';
        break;
    case 6:
        result = '6';
        break;
    case 7:
        result = '7';
        break;
    case 8:
        result = '8';
        break;
    case 9:
        result = '9';
        break;
    case 10:
        result = 'a';
        break;
    case 11:
        result = 'b';
        break;
    case 12:
        result = 'c';
        break;
    case 13:
        result = 'd';
        break;
    case 14:
        result = 'e';
        break;
    case 15:
        result = 'f';
        break;
    default: result = '0';
    }
    return result;
}




int hexValue(char n) {
    int result = 0;
    switch (n) {
    case '0':
        result = 0;
        break;
    case '1':
        result = 1;
        break;
    case '2':
        result = 2;
        break;
    case '3':
        result = 3;
        break;
    case '4':
        result = 4;
        break;
    case '5':
        result = 5;
        break;
    case '6':
        result = 6;
        break;
    case '7':
        result = 7;
        break;
    case '8':
        result = 8;
        break;
    case '9':
        result = 9;
        break;
    case 'a':
        result = 10;
        break;
    case 'b':
        result = 11;
        break;
    case 'c':
        result = 12;
        break;
    case 'd':
        result = 13;
        break;
    case 'e':
        result = 14;
        break;
    case 'f':
        result = 15;
        break;
    default: result = 0;
    }
    return result;
}

// MAX and MIN needs to be defined
int hex4digitValueWrap(int n) {
    if (n > LONG_MAX) {
        n = +(n - MAX);
    }
    else if (n < MIN) {
        n = MAX + (n - MIN);
    }
    return n;
}



// required <regex> and <algorithm> library for std::transform() function

char* cleanCharHex(char toClean[]) {
    // Set up the result.
    char* result = makeBlankChar5().data();

    // Convert toClean to a string for use of some functions.
    std::string input(toClean);
    input = std::regex_replace(input, std::regex("^ +| +$|( ) +"), "$1");
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    input = std::regex_replace(input, std::regex("[^+-0-9a-f]"), "");

    // check for negative (result will be set to positive by default)
    if (input[0] == '-') { result[0] = '-'; }

    // clean out the sign
    input = std::regex_replace(input, std::regex("[+-]"), "");

    // Double countdown loop,
    // Counting down from the last index of each to fill in result starting from the 1's digit.
    int toCleanIndex = input.length() - 1;
    int resultIndex = 4;
    while ((resultIndex > -1) && (toCleanIndex > -1)) {
        result[resultIndex] = input[toCleanIndex];
        resultIndex--;
        toCleanIndex--;
    }
    return result;
}



int signToInt(char c) {
    int result = 1;
    if (c == '-') {
        result = -1;
    }
    return result;
}

std::array<char, 5> makeBlankChar5() {
    std::array<char, 5> array;
    array[0] = '+';
    for (int i = 1; i < 5; i++) {
        array[i] = '0';
    }
    return array;
}

std::array<char, 5> cleanCharHex(std::array<char, 5> toClean) {
    std::array<char, 5> result = makeBlankChar5();
    std::string input(toClean.begin(), toClean.end());
    input = std::string(toClean.begin(), toClean.end());
    input = std::regex_replace(input, std::regex("[^+-0-9a-f]"), "");
    input = std::regex_replace(input, std::regex("[+-]"), "");

    if (input[0] == '-') {
        result[0] = '-';
    }

    int toCleanIndex = input.length() - 1;
    int resultIndex = 4;
    while ((resultIndex > -1) && (toCleanIndex > -1)) {
        result[resultIndex] = input[toCleanIndex];
        resultIndex--;
        toCleanIndex--;
    }
    return result;
}

