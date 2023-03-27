#include "pch.h"
#include "ProgramState/ProgramState.h"
#include "Hex4digit.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

ProgramState* programState;

TEST(WithEmptyArray_ReturnsFalse, InitializeState) {
    std::vector<Hex4digit> emptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);

    bool result = programState->initializeState(emptyInstructions);

    EXPECT_FALSE(result);
}