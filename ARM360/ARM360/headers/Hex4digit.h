
#pragma once
#include <string>
#include <regex>
#include "HexadecimalConverter.h"

class Hex4digit {
private:
    int hex;

public:
    Hex4digit();
    Hex4digit(std::array<char, 5> value);
    Hex4digit(std::string value);
    Hex4digit(int value);
    void setValue(int number);
    void setValue(std::string number);
    void setValue(std::array<char, 5> number);
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
    std::array<char, 5> getHexChars();
    std::array<char, 5> getSignedHexChars();
    std::string getString();
    int getMiddle2Value();
    int getLast2Value();
    static char hexChar(int n);
    static int hexValue(char n);
};