
#include <string>
#include "Hex4digit.h"
#include "HexadecimalConverter.h"

class Hex4digit {
private:
    int hex;

public:
    Hex4digit();
    //  hex = 0;

    Hex4digit(char* value);
    // hex = HexadecimalConverter::hexToDecimal(value);

    Hex4digit(std::string value);
    // hex = HexadecimalConverter::hexToDecimal(value.c_str());

    Hex4digit(int value);
    // hex = value;

    void setValue(int number);
    // hex = number;

    void setValue(std::string number);
    //hex = HexadecimalConverter::hexToDecimal(number.c_str());

    void setValue(char* number);
    // hex = HexadecimalConverter::hexToDecimal(number);

    void setFirst(char first);
    
    void setSecond(char second);
    
    void setThird(char third);
    
    void setFourth(char fourth);
    
    bool isPositive();
    
    char getSign();
    
    char getFirst();
    
    char getSecond();
    
    char getThird();
    
    char getFourth();
    
    int getValue();
    
    char* getHexChars();
};