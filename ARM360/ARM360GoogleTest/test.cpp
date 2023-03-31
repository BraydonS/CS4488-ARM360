#include "pch.h"
#include "../ARM360/headers/ProgramState/ProgramState.h"
#include "Hex4digit.h"
#include "MemoryHistorySpace.h"

TEST(TestCaseNameTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

ProgramState* programState = programState->getInstance();



TEST(ProgramStateTest, ProgramStateTest) {
        std::vector<Hex4digit> emptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);

        bool result = programState->initializeState(emptyInstructions);

        EXPECT_FALSE(result);
}