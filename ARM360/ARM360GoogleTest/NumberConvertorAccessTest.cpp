#include "gtest/gtest.h"
#include "NumberConvertorAccess.h"
#include "Hex4digit.h"
#include "gtest/gtest.h"
#include "../../ARM360/headers/NumberConvertorAccess.h"
#include "../../ARM360/headers/stdafx.h"
#include "../../ARM360/headers/Hex4digit.h"
#include "../../ARM360/headers/HexadecimalConverter.h"
#include "../ARM360/src/NumberConvertorAccess.cpp"


class NumberConvertorAccessTest : public ::testing::Test {
protected:
    NumberConvertorAccess numberConvertor;
};

TEST_F(NumberConvertorAccessTest, convertToHexChars) {
    // Test a positive number
    char* result = numberConvertor.convertToHexChars(255);
    ASSERT_STREQ("00FF", result);
    delete[] result;

    // Test a negative number
    result = numberConvertor.convertToHexChars(-255);
    ASSERT_STREQ("FF01", result);
    delete[] result;

    // Test zero
    result = numberConvertor.convertToHexChars(0);
    ASSERT_STREQ("0000", result);
    delete[] result;
}

TEST_F(NumberConvertorAccessTest, convertToHexChars) {
    // Test a positive number
    short number = 255;
    char* hexString = numberConvertor.convertToHexChars(number);
    std::string hexStringStr(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("00FF", hexStringStr);

    // Test a negative number
    number = -255;
    hexString = numberConvertor.convertToHexChars(number);
    hexStringStr = std::string(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("FF01", hexStringStr);

    // Test zero
    number = 0;
    hexString = numberConvertor.convertToHexChars(number);
    hexStringStr = std::string(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("0000", hexStringStr);

    // Clean up the allocated memory
    delete[] hexString;
}
