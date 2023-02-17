// MockDataGenerator Header file
// Show Pratoomratana
// 01/27/23

#pragma once
#include <vector>
class MockDataGenerator{
    
    public: 
        static char getRandomHexChar();

        static int getRandomHexValue();

        static int getRandomHexValue4();

        static std::vector<char> getRandomHexChar5();

        static std::vector<char> getJunkChar4();

        static char getJunkChar();
};