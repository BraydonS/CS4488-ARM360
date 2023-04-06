#include "pch.h"
#include "HexadecimalConverter.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/HexadecimalConverter.h"


Hex4digit hex4Digit;
HexadecimalConverter hexConv;

//// Object initalizaton before every test
//TEST_METHOD_INITIALIZE(Hex4DigitInit) {
//	Hex4digit hex4Digit;
//	HexadecimalConverter hexConv;
//}
//
//// Object deletion after every test
//TEST_METHOD_CLEANUP(Hex4DigitCleanup) {
//	delete& hex4Digit;
//	delete& hexConv;
//}

TEST(Hex4Digit, setValueIntTest) {
	hex4Digit.setValue(int(3));
	EXPECT_EQ(hexConv.decimalToHex(3)[1], hex4Digit.getFirst());
}

TEST(Hex4Digit, setValueStringTest) {
	hex4Digit.setValue(std::string("4"));
	EXPECT_EQ(hexConv.decimalToHex(4)[1], hex4Digit.getFirst());
}

TEST(Hex4Digit, setValueCharArrayTest) {
	//std::array<char, 5> charArray = { "1" };
	hex4Digit.setValue(1);
	EXPECT_EQ(1, hex4Digit.getValue());
}

TEST(Hex4Digit, setFirstTest) {
	hex4Digit.setValue(std::string("4"));
	hex4Digit.setFirst(char('5'));
	EXPECT_EQ(hexConv.decimalToHex('5')[1], hex4Digit.getFirst());
}

TEST(Hex4Digit, setSecondTest) {
	hex4Digit.setValue(std::string("4"));
	hex4Digit.setSecond(char('2'));
	EXPECT_EQ(hexConv.decimalToHex('2')[1], hex4Digit.getSecond());
}

TEST(Hex4Digit, setThirdTest) {
	hex4Digit.setValue(std::string("4"));
	hex4Digit.setThird(char('3'));
	EXPECT_EQ(hexConv.decimalToHex('3')[1], hex4Digit.getThird());
}

TEST(Hex4Digit, setFourthTest) {
	hex4Digit.setValue(std::string("4"));
	hex4Digit.setFourth(char('4'));
	EXPECT_EQ(hexConv.decimalToHex('4')[1], hex4Digit.getFourth());
}

TEST(Hex4Digit, getValueTest) {
	hex4Digit.setValue(15);
	EXPECT_EQ(15, hex4Digit.getValue());
}

// Converts a integer to hex value.
TEST(Hex4Digit, getHexCharsTest) {
	std::array<char, 5> array = {'000b'};
	hex4Digit.setValue(11);
	// C++ kept removing leading 0s from this array so called index in comparision
	EXPECT_EQ(array[0], hex4Digit.getHexChars()[3]);
}

TEST(Hex4Digit, getStringTest) {
	std::string testString = "+0002";
	hex4Digit.setValue(2);
	EXPECT_EQ(testString, hex4Digit.getString());
}

// See getLast2ValueTest for strange behaivor.
// With the indexing issue this effectly gets the last 2 values.
TEST(Hex4Digit, getMiddle2ValueTest) {
	hex4Digit.setValue(17);
	EXPECT_EQ(17, hex4Digit.getMiddle2Value());
}

// These function don't behave how I think they should.
// Right now it's multiplying the last number by 16. [3] because [4] will always be the null terminator.
// We might want to reindex this to be [2] and [3] respecivly.
// Right now, this function effectly gets the last decimal number and mutliplies it by 16.
TEST(Hex4Digit, getLast2ValueTest) {
	hex4Digit.setValue(5);
	EXPECT_EQ(80, hex4Digit.getLast2Value ());
}

TEST(Hex4Digit, hexCharTest) {
	EXPECT_EQ('1', hex4Digit.hexChar(1));
}

TEST(Hex4Digit, hexValueTest) {
	EXPECT_EQ(3, hex4Digit.hexValue('3'));
}
