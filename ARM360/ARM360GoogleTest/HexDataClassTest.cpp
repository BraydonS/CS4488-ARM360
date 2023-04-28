#include "gtest/gtest.h"
#include "HexDataClass.h"

class HexDataClassTest : public ::testing::Test {
protected:
    HexDataClass hexData;
};

TEST_F(HexDataClassTest, SetValue_Integer) {
    hexData.setValue(0x12345678);
    EXPECT_EQ(hexData.getValue(), 0x12345678);
}

TEST_F(HexDataClassTest, SetValue_String) {
    hexData.setValue("ABCD");
    EXPECT_EQ(hexData.getValue(), 0xABCD);
}

TEST_F(HexDataClassTest, GetHexChars) {
    hexData.setValue(0x12);
    std::vector<char> expected = { '1', '2' };
    EXPECT_EQ(hexData.getHexChars(), expected);
}

TEST_F(HexDataClassTest, GetMiddle2Value) {
    hexData.setValue(0x123456);
    EXPECT_EQ(hexData.getMiddle2Value(), 0x34);
}

TEST_F(HexDataClassTest, GetLast2Value) {
    hexData.setValue(0x123456);
    EXPECT_EQ(hexData.getLast2Value(), 0x56);
}
