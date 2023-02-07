// MockDataGenerator Header file
// Show Pratoomratana
// 01/27/23

// .h file for development so the IDE can reconize the classes we have yet to implement.
#pragma once
#include <vector>

class MockDataGenerator{
    
    public: 
        char getRandomHexChar();

        static int getRandomHexValue();

        static int getRandomHexValue4();

        static int getRandomHexValue5();

        // Originally a char[], but we will use a vector instead
        static std::vector<char> getRandomHexChar5();

        static char* getJunkChar4();

        // Again, originally a char[]
        std::vector<char> getJunkChar();
};