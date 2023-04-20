#include "stdafx.h"
#include "Hex4digit.h"

/// <summary>
/// Default constructor for Hex4digit
/// </summary>
Hex4digit::Hex4digit() : hex(0) {}

/// <summary>
/// Constructor for Hex4Digit that takes an initial value of the form array<char, 5>
/// </summary>
/// <param name="value">std::array<char, 5></param>
Hex4digit::Hex4digit(std::array<char, 5> value) : hex(HexadecimalConverter::hexToDecimal(value.data())) {}

/// <summary>
/// Constructor for Hex4Digit that takes an initial value of the form string
/// </summary>
/// <param name="value">std::string</param>
Hex4digit::Hex4digit(std::string value) : hex(HexadecimalConverter::hexToDecimal(value.data())) {}

/// <summary>
/// Constructor for Hex4Digit that takes an initial value of the form int
/// </summary>
/// <param name="value">int</param>
Hex4digit::Hex4digit(int value) : hex(value) {}

/// <summary>
/// Method that sets the value
/// </summary>
/// <param name="number">int : The value to set</param>
void Hex4digit::setValue(int number) {
    hex = number;
}

/// <summary>
/// Method that sets the value
/// </summary>
/// <param name="number">std::string : The value to set</param>
void Hex4digit::setValue(std::string number) {
    // Convert the input string to decimal and store in hex
    hex = HexadecimalConverter::hexToDecimal(const_cast<char*>(number.c_str()));

    // Convert the input string to a fixed-size char array
    std::array<char, 5> arr{};
    std::copy_n(number.begin(), std::min(number.size(), arr.size()), arr.begin());

    // Convert the char array to decimal and store in hex
    hex = HexadecimalConverter::hexToDecimal(arr.data());
}

/// <summary>
/// Method that sets the value
/// </summary>
/// <param name="number">std::array<char, 5> : The value to set</param>
void Hex4digit::setValue(std::array<char, 5> number) {
    hex = HexadecimalConverter::hexToDecimal(number.data());
}

/// <summary>
/// Method that sets the first char of the value
/// </summary>
/// <param name="first">The desired char</param>
void Hex4digit::setFirst(char first) {
    std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
    change[1] = first;
    hex = HexadecimalConverter::hexToDecimal(change.data());
}

/// <summary>
/// Method that sets the second char of the value
/// </summary>
/// <param name="second">The desired char</param>
void Hex4digit::setSecond(char second) {
    std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
    change[2] = second;
    hex = HexadecimalConverter::hexToDecimal(change.data());
}

/// <summary>
/// Method that sets the third char of the value
/// </summary>
/// <param name="third">The desired char</param>
void Hex4digit::setThird(char third) {
    std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
    change[3] = third;
    hex = HexadecimalConverter::hexToDecimal(change.data());
}

/// <summary>
/// Method that sets the fourth char of the value
/// </summary>
/// <param name="fourth">The desired char</param>
void Hex4digit::setFourth(char fourth) {
    std::array<char, 5> change = HexadecimalConverter::decimalToHex(hex);
    change[4] = fourth;
    hex = HexadecimalConverter::hexToDecimal(change.data());
}

/// <summary>
/// Method that checks if the value is positive
/// </summary>
/// <returns>bool : True if positive; False otherwise</returns>
bool Hex4digit::isPositive() {
    return hex >= 0;
}

/// <summary>
/// Methjod that gets the sign of the value
/// </summary>
/// <returns>'+' if positive; '-' otherwise</returns>
char Hex4digit::getSign() {
    return isPositive() ? '+' : '-';
}

/// <summary>
/// Method that gets the first char of the value
/// </summary>
/// <returns>The first char</returns>
char Hex4digit::getFirst() {
    return HexadecimalConverter::decimalToHex(hex)[1];
}

/// <summary>
/// Method that gets the second char of the value
/// </summary>
/// <returns>The second char</returns>
char Hex4digit::getSecond() {
    return HexadecimalConverter::decimalToHex(hex)[2];
}

/// <summary>
/// Method that gets the third char of the value
/// </summary>
/// <returns>The thrid char</returns>
char Hex4digit::getThird() {
    return HexadecimalConverter::decimalToHex(hex)[3];
}

/// <summary>
/// Method that gets the fourth char of the value
/// </summary>
/// <returns>The fourth char</returns>
char Hex4digit::getFourth() {
    return HexadecimalConverter::decimalToHex(hex)[4];
}

/// <summary>
/// Method that gets the value
/// </summary>
/// <returns>The value in int form</returns>
int Hex4digit::getValue() {
    return hex;
}

/// <summary>
/// Method that returns the value as an array of chars in hexadecimal
/// </summary>
/// <returns>std::array<char, 5></returns>
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

/// <summary>
/// Method that returns the value as an array of chars in hexadecimal with sign
/// </summary>
/// <returns>std::array<char, 5> with sign</returns>
std::array<char, 5> Hex4digit::getSignedHexChars() {
    return HexadecimalConverter::decimalToHex(hex);
}

/// <summary>
/// Method that returns the value as a string
/// </summary>
/// <returns>std::string</returns>
std::string Hex4digit::getString() {
    std::string str = "";
    std::array<char, 5> temp = Hex4digit::getSignedHexChars();
    for (int i = 0; i < temp.size(); i++) {
        str += temp[i];
    }
    return str;
}

/// <summary>
/// Return the integer sum of the middle digits.
/// For determining a memory space value from inside an instruction, when the memory space is first
/// Given a decimal number, convert to hex.Take the middle 2 digits of the hex and convert back to decimal
/// </summary>
/// <returns>the integer sum of the 2nd and 3rd digit</returns>
int Hex4digit::getMiddle2Value() {
    std::array<char, 5> hexChars = getHexChars();
    int result = (HexadecimalConverter::hexValue(hexChars[1]) * 16) +
        HexadecimalConverter::hexValue(hexChars[2]);
    return result;
}

/// <summary>
/// Return the integer sum of the last 2 digits.
/// For determining a memory space value from inside an instruction, when the memory space is LAST
/// Given a decimal number, convert to hex.Take the last 2 digits of the hex and convert back to decimal
/// </summary>
/// <returns>the integer sum of the 3rd and 4th digit</returns>
int Hex4digit::getLast2Value() {
    std::array<char, 5> hexChars = getHexChars();
    int result = (HexadecimalConverter::hexValue(hexChars[2]) * 16) +
        HexadecimalConverter::hexValue(hexChars[3]);
    return result;
}

/// <summary>
/// Method that converts an int to a hexadecimal value
/// </summary>
/// <param name="n">The value to convert</param>
/// <returns>A hexadeciaml value</returns>
char Hex4digit::hexChar(int n) {
    return HexadecimalConverter::hexChar(n);
}

/// <summary>
/// Method that converts a char to a hexadeciaml value
/// </summary>
/// <param name="n">The value to convert</param>
/// <returns>A hexadeciaml value</returns>
int Hex4digit::hexValue(char n) {
    return HexadecimalConverter::hexValue(n);
}