
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "stdafx.h"
#include "NumberConvertorAccess.h"
#include "Hex4digit.h"





using namespace std;

class NumberConvertorAccess {
public:


    
    // Converts a short integer to a char array of its hexadecimal representation
    // Returns a pointer to the char array
    virtual char* convertToHexChars(short number) {
        // Allocate memory for the hex string, which has a maximum length of 4 characters plus the null terminator
        char* hexString = new char[5];
        // Use sprintf to convert the number to hexadecimal and store the result in hexString
        sprintf(hexString, "%04X", number);
        // Return the pointer to the char array
        return hexString;
    }

    // Converts a char array of a hexadecimal representation to an integer
    // Returns the integer value
    virtual int convertToInt(char* number) {
        // Use strtol to convert the hex string to an integer
        // The base parameter is set to 16 to indicate that the input string is in hexadecimal format
        int result = strtol(number, NULL, 16);
        // Return the integer value
        return result;
    }








};

