#pragma once
#include <string>
#include <vector>

class HexDataClass {
public:
    void setValue(int number);
    void setValue(std::string number);
    int getValue();
    std::vector<char> getHexChars();
    int getMiddle2Value();
    int getLast2Value();
};