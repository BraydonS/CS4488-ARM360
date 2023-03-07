// MockDataGenerator source file
// Show Pratoomratana
// 02/05/23
#include <stdlib.h>
#include "stdafx.h"
#include "MockDataGenerator.h"

// Class to generate random data character.

// Generates a single random hex character
// @return char : a random hex character
char MockDataGenerator::getRandomHexChar(){
    char result = '0';
    // Random number between 0 and 15
    int randomInt = rand()%16;
    result = Hex4digit::hexChar(randomInt);
    return result;
}

// Generate a single random number 
// @return int : a random int between 0 - 15
int MockDataGenerator::getRandomHexValue(){
    return rand()%16;
}

// Generate a random hex value, posative or negative. 
// @return int : a random hex value
int MockDataGenerator::getRandomHexValue4(){
    int result = 1;
    result = result * (rand()%15 + 1);
    //result = result * (rand()%15 + 1);
    //result = result * (rand()%15 + 1);
    //result = result * (rand()%15 + 1);
    // rand() doesn't have a boolean random operator so this is a workaround even = true, odd = false
    if ((rand()%10) % 2 == 0){
        result = result * -1;
    }
    return result;
}

// Function to make a vector<char> of random hex character that could be positive or negative.
// return result : a vector<char> of random hex numbers.
std::vector<char> MockDataGenerator::getRandomHexChar5(){
    std::vector<char> result(5);
    for(int x = 0; x < 5; x++){
        result[x] = getRandomHexChar();
    }
    result[0] = '-';
    if ((rand()%10) % 2 == 0){
        result[0] = '+';
    }
    return result;
}

// Generates a random (non-hex) character
// @return result : A random char.
char MockDataGenerator::getJunkChar(){
    char result = '0';
    int c = rand()%16;
    result = (char)(c + 103); // ASCII char 103 is 'g', so g to v for the random char.
    return result;
}

// Generates a random vector<char>
// @return result : a random vector<char>
std::vector<char> MockDataGenerator::getJunkChar4(){
    std::vector<char> result(4);
    for (int x=0; x < 4; x++){
        result[x] = getJunkChar();
    }
    return result;
}
