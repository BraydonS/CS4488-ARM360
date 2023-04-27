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

TEST(Hex4Digit, getHexCharsTest) {
	std::array<char, 5> expectedResult = {'+','0','0','0','b'};
	hex4Digit.setValue(11);
	std::array<char, 5> result = hex4Digit.getHexChars();
	EXPECT_EQ(expectedResult, result);
}

TEST(Hex4Digit, getStringTest) {
	std::string testString = "+0002";
	hex4Digit.setValue(2);
	EXPECT_EQ(testString, hex4Digit.getString());
}

TEST(Hex4Digit, getMiddle2ValueTest) {
	hex4Digit.setValue(3456); // 3456(dec) = D80(Hex)
	EXPECT_EQ(216, hex4Digit.getMiddle2Value()); // D8(Hex) = 216(dec)
}

TEST(Hex4Digit, getLast2ValueTest) {
	hex4Digit.setValue(5674); // 5674(dec) = 162A(Hex)
	EXPECT_EQ(42, hex4Digit.getLast2Value()); // 2A(Hex) = 42(dec)
}

TEST(Hex4Digit, hexCharTest) {
	EXPECT_EQ('1', hex4Digit.hexChar(1));
}

TEST(Hex4Digit, hexValueTest) {
	EXPECT_EQ(3, hex4Digit.hexValue('3'));
}
