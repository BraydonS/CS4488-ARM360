#include "stdafx.h"
//#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "HexDataClass.h"


//declared value_ as integer
int value_;

//Sets the value of HexDataClass to specified integer
void HexDataClass::setValue(int number) {
	
	value_ = number;
}


void HexDataClass::setValue(std::string number) {
	// Create a stringstream from the string number.
	std::stringstream ss(number);
	// Read the integer value in hexadecimal format from the stringstream into the value_ member variable.
	ss >> std::hex >> value_;
}
int HexDataClass::getValue() const{
	// Stop compile error
	return -1;
}
std::vector<char> HexDataClass::getHexChars() const {
	// Create a stringstream and output the current value in hexadecimal format to it.
	std::stringstream ss;
	ss << std::hex << value_;
	// Extract the hexadecimal string from the stringstream.
	std::string hexString = ss.str();
	// Create a vector from the hexadecimal string by copying its characters.
	std::vector<char> hexChars(hexString.begin(), hexString.end());
	return hexChars;
}

int HexDataClass::getMiddle2Value() const{
	// Convert the current value to a hexadecimal string.
	std::stringstream ss;
	ss << std::hex << value_;
	std::string hexString = ss.str();
	// Extract the middle two hexadecimal digits from the string.
	std::string middle2String = hexString.substr(2, 2);
	// Convert the middle two hexadecimal digits to an integer value.
	int middle2Value;
	std::stringstream middle2ss(middle2String);
	middle2ss >> std::hex >> middle2Value;
	return middle2Value;
}
int HexDataClass::getLast2Value() const{
	//Extracts the last two hexadecimal digits of the current value.
	return value_ & 0xFF;
}