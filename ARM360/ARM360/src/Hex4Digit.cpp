#include <string>
#include <cstring>
#include <array>
#include <algorithm>
#include "HexadecimalConvertor.h"
#include "Hex4Digit.h"


class HexDataClass {
public:
    virtual void setValue(int number) = 0;
    virtual void setValue(std::string number) = 0;
    virtual int getValue() = 0;
    virtual std::array<char, 5> getHexChars() = 0;
    virtual int getMiddle2Value() = 0;
};

namespace HexadecimalConverter {
    int hexToDecimal(std::array<char, 5> value);
    std::array<char, 5> decimalToHex(int decimal);
    int hexValue(char hexChar);
}

class Hex4digit : public HexDataClass {
private:
    int hex;

public:
    Hex4digit() : hex(0) {};
    Hex4digit(std::array<char, 5> value) : hex(HexadecimalConverter::hexToDecimal(value)) {};
    Hex4digit(int value) : hex(value) {};

    void setValue(int number) override { hex = number; };

    void setValue(std::string number) override {
        std::array<char, 5> arr{};
        std::copy(number.begin(), number.end(), arr.begin());
        hex = HexadecimalConverter::hexToDecimal(arr);
    };

    void setValue(std::array<char, 5> number) { hex = HexadecimalConverter::hexToDecimal(number); };
    void setFirst(char first) {
        std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
        change[1] = first;
        hex = HexadecimalConverter::hexToDecimal(change);
    }
    void setSecond(char second) {
        std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
        change[2] = second;
        hex = HexadecimalConverter::hexToDecimal(change);
    }
    void setThird(char third) {
        std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
        change[3] = third;
        hex = HexadecimalConverter::hexToDecimal(change);
    }
    void setFourth(char fourth) {
        std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
        change[4] = fourth;
        hex = HexadecimalConverter::hexToDecimal(change);
    }

    bool isPositive() { return hex >= 0; };
    char getSign() {
        return isPositive() ? '+' : '-';
    }
    char getFirst() {
        return HexadecimalConverter::decimalToHex(hex)[1];
    }
    char getSecond() {
        return HexadecimalConverter::decimalToHex(hex)[2];
    }
    char getThird() {
        return HexadecimalConverter::decimalToHex(hex)[3];
    }
    char getFourth() {
        return HexadecimalConverter::decimalToHex(hex)[4];
    }
    int getValue() override {
        return hex;
    }

    std::array<char, 5> getHexChars() override {
        return HexadecimalConverter::decimalToHex(hex);
    }

    int getMiddle2Value() override {
        std::array<char, 5> hexChars = getHexChars();
        int result = (HexadecimalConvertor::hexValue(hexChars[2]) * 16) +
            HexadecimalConverter::hexValue(hexChars[3]);
        return result;
    }

    char hexChar(int n) {
        return HexadecimalConvertor::hexChar(n);
    }

    static int hexValue(char n) {

        return HexadecimalConverter::hexValue(n);
    }

};