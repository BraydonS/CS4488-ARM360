#include "gtest/gtest.h"
#include "MemoryHistorySpace.h"

// Test fixture for MemoryHistorySpace class
class MemoryHistorySpaceTest : public ::testing::Test {
protected:
    MemoryHistorySpace mem;

    void SetUp() override {
        // Set up any initial state for the test fixture
        mem.setMemoryLocation(1000);
        mem.setValue(Hex4digit(0x1234));
    }
};

// Test for getMemoryLocation method
TEST_F(MemoryHistorySpaceTest, GetMemoryLocation) {
    EXPECT_EQ(mem.getMemoryLocation(), 1000);
}

// Test for setMemoryLocation method
TEST_F(MemoryHistorySpaceTest, SetMemoryLocation) {
    mem.setMemoryLocation(2000);
    EXPECT_EQ(mem.getMemoryLocation(), 2000);
}

