
#include "pch.h"
#include "arm360.h"
#include <iostream>
#include <fstream>

#include <gtest/gtest.h>
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/HexDataClass.h"
#include "gtest/gtest.h"
#include "../../ARM360/headers/HexadecimalConverter.h"
#include <string>
#include <array>

#include "../../ARM360/headers/stdafx.h"





// Test the HexadecimalConverter::hexToDecimal() function.
TEST(HexadecimalConverterTest, hexToDecimalTest) {
    char hex1[] = "7b";
    char hex2[] = "-7b";
    char hex3[] = "0";
    char hex4[] = "ffffffff";
    char hex5[] = "-ffffffff";

    ASSERT_EQ(HexadecimalConverter::hexToDecimal(hex1), 123);
    ASSERT_EQ(HexadecimalConverter::hexToDecimal(hex2), -123);
    ASSERT_EQ(HexadecimalConverter::hexToDecimal(hex3), 0);
    ASSERT_EQ(HexadecimalConverter::hexToDecimal(hex4), -1);
    ASSERT_EQ(HexadecimalConverter::hexToDecimal(hex5), LONG_MIN);
}

// Test the HexadecimalConverter::decimalToHex() function.
TEST(HexadecimalConverterTest, decimalToHexTest) {
    int dec1 = 123;
    int dec2 = -123;
    int dec3 = 0;
    int dec4 = -1;
    int dec5 = LONG_MIN;

    std::array<char, 5> hex1 = { '0', '7', 'b', '\0', '\0' };
    std::array<char, 5> hex2 = { '-', '7', 'b', '\0', '\0' };
    std::array<char, 5> hex3 = { '0', '0', '0', '0', '\0' };
    std::array<char, 5> hex4 = { '-', '1', '\0', '\0', '\0' };
    std::array<char, 5> hex5 = { '-', '8', '0', '0', '0' };

    ASSERT_EQ(HexadecimalConverter::decimalToHex(dec1), hex1);
    ASSERT_EQ(HexadecimalConverter::decimalToHex(dec2), hex2);
    ASSERT_EQ(HexadecimalConverter::decimalToHex(dec3), hex3);
    ASSERT_EQ(HexadecimalConverter::decimalToHex(dec4), hex4);
    ASSERT_EQ(HexadecimalConverter::decimalToHex(dec5), hex5);
}



// Test the HexadecimalConverter::hexChar() function.
TEST(HexadecimalConverterTest, hexCharTest) {
    ASSERT_EQ(HexadecimalConverter::hexChar(0), '0');
    ASSERT_EQ(HexadecimalConverter::hexChar(1), '1');
    ASSERT_EQ(HexadecimalConverter::hexChar(2), '2');
    ASSERT_EQ(HexadecimalConverter::hexChar(3), '3');
    ASSERT_EQ(HexadecimalConverter::hexChar(4), '4');
    ASSERT_EQ(HexadecimalConverter::hexChar(5), '5');
    ASSERT_EQ(HexadecimalConverter::hexChar(6), '6');
    ASSERT_EQ(HexadecimalConverter::hexChar(7), '7');
    ASSERT_EQ(HexadecimalConverter::hexChar(8), '8');
    ASSERT_EQ(HexadecimalConverter::hexChar(9), '9');
    ASSERT_EQ(HexadecimalConverter::hexChar(10), 'a');
    ASSERT_EQ(HexadecimalConverter::hexChar(11), 'b');
    ASSERT_EQ(HexadecimalConverter::hexChar(12), 'c');
    ASSERT_EQ(HexadecimalConverter::hexChar(13), 'd');
    ASSERT_EQ(HexadecimalConverter::hexChar(14), 'e');
    ASSERT_EQ(HexadecimalConverter::hexChar(15), 'f');
}





TEST(HexadecimalConverterTest, HexValue) {
    // Test all possible input characters
    EXPECT_EQ(HexadecimalConverter::hexValue('0'), 0);
    EXPECT_EQ(HexadecimalConverter::hexValue('1'), 1);
    EXPECT_EQ(HexadecimalConverter::hexValue('2'), 2);
    EXPECT_EQ(HexadecimalConverter::hexValue('3'), 3);
    EXPECT_EQ(HexadecimalConverter::hexValue('4'), 4);
    EXPECT_EQ(HexadecimalConverter::hexValue('5'), 5);
    EXPECT_EQ(HexadecimalConverter::hexValue('6'), 6);
    EXPECT_EQ(HexadecimalConverter::hexValue('7'), 7);
    EXPECT_EQ(HexadecimalConverter::hexValue('8'), 8);
    EXPECT_EQ(HexadecimalConverter::hexValue('9'), 9);
    EXPECT_EQ(HexadecimalConverter::hexValue('a'), 10);
    EXPECT_EQ(HexadecimalConverter::hexValue('b'), 11);
    EXPECT_EQ(HexadecimalConverter::hexValue('c'), 12);
    EXPECT_EQ(HexadecimalConverter::hexValue('d'), 13);
    EXPECT_EQ(HexadecimalConverter::hexValue('e'), 14);
    EXPECT_EQ(HexadecimalConverter::hexValue('f'), 15);
}



// Test class for HexadecimalConverter
class HexadecimalConverterTest : public testing::Test {
protected:
    HexadecimalConverter hexConverter; // create an instance of HexadecimalConverter
};

// Test hexToDecimal() method
TEST_F(HexadecimalConverterTest, hexToDecimal) {
    char hex1[] = "1";
    ASSERT_EQ(hexConverter.hexToDecimal(hex1), 1);

    char hex2[] = "F";
    ASSERT_EQ(hexConverter.hexToDecimal(hex2), 15);

    char hex3[] = "10";
    ASSERT_EQ(hexConverter.hexToDecimal(hex3), 16);

    char hex4[] = "-1F";
    ASSERT_EQ(hexConverter.hexToDecimal(hex4), -31);

    char hex5[] = "-80000000";
    ASSERT_EQ(hexConverter.hexToDecimal(hex5), -2147483648);
}

// Test decimalToHex() method
TEST_F(HexadecimalConverterTest, decimalToHex) {
    std::array<char, 5> hex1 = { '1', '\0', '\0', '\0', '\0' };
    ASSERT_EQ(hexConverter.decimalToHex(1), hex1);

    std::array<char, 5> hex2 = { 'F', '\0', '\0', '\0', '\0' };
    ASSERT_EQ(hexConverter.decimalToHex(15), hex2);

    std::array<char, 5> hex3 = { '1', '0', '\0', '\0', '\0' };
    ASSERT_EQ(hexConverter.decimalToHex(16), hex3);

    std::array<char, 5> hex4 = { '-', '1', 'F', '\0', '\0' };
    ASSERT_EQ(hexConverter.decimalToHex(-31), hex4);

    std::array<char, 5> hex5 = { '-', '8', '0', '0', '0' };
    ASSERT_EQ(hexConverter.decimalToHex(-2147483648), hex5);
}

// Test hexChar() method
TEST_F(HexadecimalConverterTest, hexChar) {
    ASSERT_EQ(hexConverter.hexChar(0), '0');
    ASSERT_EQ(hexConverter.hexChar(9), '9');
    ASSERT_EQ(hexConverter.hexChar(10), 'a');
    ASSERT_EQ(hexConverter.hexChar(15), 'f');
}

// Test hexValue() method
TEST_F(HexadecimalConverterTest, hexValue) {
    ASSERT_EQ(hexConverter.hexValue('0'), 0);
    ASSERT_EQ(hexConverter.hexValue('9'), 9);
    ASSERT_EQ(hexConverter.hexValue('a'), 10);
    ASSERT_EQ(hexConverter.hexValue('f'), 15);
}

// Test hex4digitValueWrap() method
TEST_F(HexadecimalConverterTest, hex4digitValueWrap) {
    ASSERT_EQ(hexConverter.hex4digitValueWrap(16), 16);
    ASSERT_EQ(hexConverter.hex4digitValueWrap(-1), 4294967295);
    ASSERT_EQ(hexConverter.hex4digitValueWrap(4294967295), -1);
    ASSERT_EQ(hexConverter.hex4digitValueWrap(2147483647), 2147483647);
    ASSERT_EQ(hexConverter.hex4digitValueWrap(-2147483648), -2147483648);

}



