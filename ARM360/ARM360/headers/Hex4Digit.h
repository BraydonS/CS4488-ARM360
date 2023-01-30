#include <string>

class Hex4digit {
private:
    int hex;

public:
    Hex4digit() {
        hex = 0;
    }

    Hex4digit(char* value) {
        hex = HexadecimalConverter::hexToDecimal(value);
    }

    Hex4digit(std::string value) {
        hex = HexadecimalConverter::hexToDecimal(value.c_str());
    }

    Hex4digit(int value) {
        hex = value;
    }

    void setValue(int number) {
        hex = number;
    }

    void setValue(std::string number) {
        hex = HexadecimalConverter::hexToDecimal(number.c_str());
    }

    void setValue(char* number) {
        hex = HexadecimalConverter::hexToDecimal(number);
    }

    void setFirst(char first) {
        char change[5];
        HexadecimalConverter::decimalToHex(hex, change);
        change[1] = first;
        hex = HexadecimalConverter::hexToDecimal(change);
    }

    void setSecond(char second) {
        char change[5];
        HexadecimalConverter::decimalToHex(hex, change);
        change[2] = second;
        hex = HexadecimalConverter::hexToDecimal(change);
    }

    void setThird(char third) {
        char change[5];
        HexadecimalConverter::decimalToHex(hex, change);
        change[3] = third;
        hex = HexadecimalConverter::hexToDecimal(change);
    }

    void setFourth(char fourth) {
        char change[5];
        HexadecimalConverter::decimalToHex(hex, change);
        change[4] = fourth;
        hex = HexadecimalConverter::hexToDecimal(change);
    }

    bool isPositive() {
        return (hex >= 0);
    }

    char getSign() {
        if (this->isPositive()) {
            return '+';
        }
        return '-';
    }

    char getFirst() {
        char hexChars[5];
        HexadecimalConverter::decimalToHex(hex, hexChars);
        return hexChars[1];
    }

    char getSecond() {
        char hexChars[5];
        HexadecimalConverter::decimalToHex(hex, hexChars);
        return hexChars[2];
    }

    char getThird() {
        char hexChars[5];
        HexadecimalConverter::decimalToHex(hex, hexChars);
        return hexChars[3];
    }

    char getFourth() {
        char hexChars[5];
        HexadecimalConverter::decimalToHex(hex, hexChars);
        return hexChars[4];
    }

    int getValue() {
        return hex;
    }

    char* getHexChars() {
