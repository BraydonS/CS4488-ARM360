#include <stdlib.h>
#include <Hex4digit.h>

// Class to generate random data character.
class MockDataGenerator{

public:

    // Starting from a, add 1-25 to the ascii value. Effectivly making it a random char generator
    char randomChar = 'a' + rand()%26;
    
    // Generates a single random hex character
    // @return char : a random hex character
    static char getRandomHexChar(){
        char result = '0';
        // Random number between 0 and 15
        int randomInt = rand()%16;
        result = Hex4digit::hexChar(randomInt);
        return result;
    }

    // Generate a single random number 
    // @return int : a random int between 0 - 15
    static int getRandomHexValue(){
        return rand()%16;
    }

    // Generate a random hex value, posative or negative. 
    // @return int : a random hex value
    static int getRandomHexVaue4(){
        int result = 1;
        result = result * (rand()%15 + 1);
        result = result * (rand()%15 + 1);
        result = result * (rand()%15 + 1);
        result = result * (rand()%15 + 1);
        // rand() doesn't have a boolean random operator so this is a workaround even = true, odd = false
        if ((rand()%10) % 2 == 0){
            result = result * -1;
        }
        return result;
    }

    // Function to make a vector<char> of random hex character that could be posative or negative.
    // return result : a vector<char> of random hex numbers.
    static std::vector<char> getRandomHexChar5(){
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

    // Generates a random character
    // @return result : A random char.
    static char getJunkChar(){
        char result = '0';
        int c = rand()%16;
        result = (char)(c + 103);
        return result;
    }

    // Generates a random vector<char>
    // @return result : a random vector<char>
    static std::vector<char> getJunkChar4(){
        std::vector<char> result(4);
        for (int x=0; x < 4; x++){
            result[x] = getJunkChar();
        }
        return result;
    }
    
};