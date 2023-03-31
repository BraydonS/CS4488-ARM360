#include "pch.h"
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
	std::array<char, 5> charArray = { "0" };
	hex4Digit.setValue(charArray);
	EXPECT_TRUE(hexConv.decimalToHex(0) == hex4Digit.getHexChars());
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
	std::array<char, 5> charArray = { "3" };
	hex4Digit.setValue(charArray);
	EXPECT_TRUE(3 == hex4Digit.getValue());
}

TEST(Hex4Digit, getHexCharsTest) {
	std::array<char, 5> array = {};
	EXPECT_TRUE(array == hex4Digit.getHexChars());
}

TEST(Hex4Digit, getSingedHexCharsTest) {
	std::array<char, 5> array = { '1' };
	hex4Digit.setValue(array);
	EXPECT_TRUE(array == hex4Digit.getSignedHexChars());
}

TEST(Hex4Digit, getStringTest) {
	std::string testString = "2";
	hex4Digit.setValue("2");
	EXPECT_EQ(testString, hex4Digit.getString());
}

TEST(Hex4Digit, getMiddle2ValueTest) {
	hex4Digit.setValue("2112");
	EXPECT_EQ(11, hex4Digit.getMiddle2Value());
}

TEST(Hex4Digit, getLast2ValueTest) {
	hex4Digit.setValue("0011");
	EXPECT_EQ(11, hex4Digit.getLast2Value());
}

TEST(Hex4Digit, hexCharTest) {
	EXPECT_EQ('1', hex4Digit.hexChar(1));
}

TEST(Hex4Digit, hexValueTest) {
	EXPECT_EQ(3, hex4Digit.hexValue('3'));
}
