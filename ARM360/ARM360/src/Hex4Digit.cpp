#include <string>
#include <cstring>
#include <array>
#include <algorithm>
#include "stdafx.h"
#include "HexadecimalConverter.h"
#include "Hex4digit.h"

Hex4digit::Hex4digit() : hex(0) {}

Hex4digit::Hex4digit(std::array<char, 5> value) : hex(HexadecimalConverter::hexToDecimal(value.data())) {}

Hex4digit::Hex4digit(std::string value) : hex(HexadecimalConverter::hexToDecimal(value.data())) {
    //std::array<char, 5> temp;
    //for (int i = 0; i < value.size(); i++) {
    //    temp[i] = value[i];
    //}
    //this->hex = HexadecimalConverter::hexToDecimal(temp);
}

Hex4digit::Hex4digit(int value) : hex(value) {}

void Hex4digit::setValue(int number) {
    hex = number;
}

void Hex4digit::setValue(std::string number) {
    // Convert the input string to decimal and store in hex
    hex = HexadecimalConverter::hexToDecimal(const_cast<char*>(number.c_str()));

    // Convert the input string to a fixed-size char array
    std::array<char, 5> arr{};
    std::copy_n(number.begin(), std::min(number.size(), arr.size()), arr.begin());

    // Convert the char array to decimal and store in hex
    hex = HexadecimalConverter::hexToDecimal(arr.data());
}



void Hex4digit::setValue(std::array<char, 5> number) {
    hex = HexadecimalConverter::hexToDecimal(number.data());
}

void Hex4digit::setFirst(char first) {
    std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
    change[1] = first;
    hex = HexadecimalConverter::hexToDecimal(change.data());
}

void Hex4digit::setSecond(char second) {
    std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
    change[2] = second;
    hex = HexadecimalConverter::hexToDecimal(change.data());
}

void Hex4digit::setThird(char third) {
    std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
    change[3] = third;
    hex = HexadecimalConverter::hexToDecimal(change.data());
}

void Hex4digit::setFourth(char fourth) {
    std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
    change[4] = fourth;
    hex = HexadecimalConverter::hexToDecimal(change.data());
}

bool Hex4digit::isPositive() {
    return hex >= 0;
}

char Hex4digit::getSign() {
    return isPositive() ? '+' : '-';
}

char Hex4digit::getFirst() {
    return HexadecimalConverter::decimalToHex(hex)[1];
}

char Hex4digit::getSecond() {
    return HexadecimalConverter::decimalToHex(hex)[2];
}

char Hex4digit::getThird() {
    return HexadecimalConverter::decimalToHex(hex)[3];
}

char Hex4digit::getFourth() {
    return HexadecimalConverter::decimalToHex(hex)[4];
}

int Hex4digit::getValue() {
    return hex;
}

std::array<char, 5> Hex4digit::getHexChars() {
    std::array<char, 5> temp = HexadecimalConverter::decimalToHex(hex);
    std::string str = "";
    // Convert to a string for regex
    for (int i = 0; i < temp.size(); i++) {
        str += temp[i];
    }
    // Use regex
    str = std::regex_replace(str, std::regex("[^0-9a-f+]"), "");
    // Copy into an std::array
    std::array<char, 5> arr = {};
    for (int i = 0; i < str.size(); i++) {
        arr[i] = str[i];
    }
    return arr;
}

std::array<char, 5> Hex4digit::getSignedHexChars() {
    return HexadecimalConverter::decimalToHex(hex);
}

std::string Hex4digit::getString() {
    std::string str = "";
    std::array<char, 5> temp = Hex4digit::getSignedHexChars();
    for (int i = 0; i < temp.size(); i++) {
        str += temp[i];
    }
    return str;
}

/**
 * Return the integer sum of the middle digits.
 * For determining a memory space value from inside an instruction, when the memory space is first
 * Given a decimal number, convert to hex. Take the middle 2 digits of the hex and convert back to decimal
 *
 * @return the integer sum of the 2nd and 3rd digit
 */
int Hex4digit::getMiddle2Value() {
    std::array<char, 5> hexChars = getHexChars();
    int result = (HexadecimalConverter::hexValue(hexChars[1]) * 16) +
        HexadecimalConverter::hexValue(hexChars[2]);
    return result;
}

/**
 * Return the integer sum of the last 2 digits.
 * For determining a memory space value from inside an instruction, when the memory space is LAST
 * Given a decimal number, convert to hex. Take the last 2 digits of the hex and convert back to decimal
 * 
 @return the integer sum of the 3rd and 4th digit
 */
int Hex4digit::getLast2Value() {
    std::array<char, 5> hexChars = getHexChars();
    int result = (HexadecimalConverter::hexValue(hexChars[2]) * 16) +
        HexadecimalConverter::hexValue(hexChars[3]);
    return result;
}

char Hex4digit::hexChar(int n) {
    return HexadecimalConverter::hexChar(n);
}

int Hex4digit::hexValue(char n) {
    return HexadecimalConverter::hexValue(n);
}