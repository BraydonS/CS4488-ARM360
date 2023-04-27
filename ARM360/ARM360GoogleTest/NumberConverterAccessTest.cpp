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
}
TEST_F(NumberConverterAccessTest, convertToHexChars_version2) {
    // Test a negative number
    char* result = numberConverter.convertToHexChars(-255);
    ASSERT_STREQ("FF01", result);
    delete[] result;
}
TEST_F(NumberConverterAccessTest, convertToHexChars_version3) {
    // Test zero
    char* result = numberConverter.convertToHexChars(0);
    ASSERT_STREQ("0000", result);
    delete[] result;
}

TEST_F(NumberConverterAccessTest, convertToHexChars_version4) {
    // Test a positive number
    short number = 255;
    char* hexString = numberConverter.convertToHexChars(number);
    std::string hexStringStr(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("00FF", hexStringStr);

    // Clean up the allocated memory
    delete[] hexString;
}
TEST_F(NumberConverterAccessTest, convertToHexChars_version5) {
    // Test a negative number
    short number = -255;
    char* hexString = numberConverter.convertToHexChars(number);
    std::string hexStringStr = std::string(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("FF01", hexStringStr);

    // Clean up the allocated memory
    delete[] hexString;
}
TEST_F(NumberConverterAccessTest, convertToHexChars_version6) {
    // Test zero
    short number = 0;
    char* hexString = numberConverter.convertToHexChars(number);
    std::string hexStringStr = std::string(hexString);
    ASSERT_EQ(4, hexStringStr.length());
    ASSERT_EQ("0000", hexStringStr);

    // Clean up the allocated memory
    delete[] hexString;
}
