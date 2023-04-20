#include "gtest/gtest.h"
#include "../../ARM360/headers/NumberConverterAccess.h"
#include "../../ARM360/headers/stdafx.h"


class NumberConverterAccessTest : public ::testing::Test {
protected:
    NumberConverterAccess numberConverter;
};

TEST_F(NumberConverterAccessTest, convertToHexChars_version1) {
    // Test a positive number
    char* result = numberConverter.convertToHexChars(255);
    ASSERT_STREQ("00FF", result);
    delete[] result;

    // Test a negative number
    result = numberConverter.convertToHexChars(-255);
    ASSERT_STREQ("FF01", result);
    delete[] result;

    // Test zero
    result = numberConverter.convertToHexChars(0);
    ASSERT_STREQ("0000", result);
    delete[] result;
}

TEST_F(NumberConverterAccessTest, convertToHexChars_version2) {
    // Test a positive number
    short number = 255;
    char* hexString = numberConverter.convertToHexChars(number);
    std::string hexStringStr(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("00FF", hexStringStr);

    // Test a negative number
    number = -255;
    hexString = numberConverter.convertToHexChars(number);
    hexStringStr = std::string(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("FF01", hexStringStr);

    // Test zero
    number = 0;
    hexString = numberConverter.convertToHexChars(number);
    hexStringStr = std::string(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("0000", hexStringStr);

    // Clean up the allocated memory
    delete[] hexString;
}
