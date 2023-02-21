#include "pch.h"
#include "CppUnitTest.h"
#include "../ARM360/headers/ProgramState/ProgramState.h"
#include "../ARM360/headers/Hex4digit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test { 

    TEST_CLASS(ProgramStateTests) {

public:

    // Test initializeState() method with empty array of instructions
    TEST_METHOD(InitializeState_WithEmptyArray_ReturnsFalse) {
        ProgramState* programState = ProgramState::getInstance();
        std::array<Hex4digit, ProgramState::TOTAL_MEMORY_SPACES> emptyInstructions;

        bool result = programState->initializeState(emptyInstructions);

        Assert::IsFalse(result);
    }

    // Test initializeState() method with non-empty array of instructions
    TEST_METHOD(InitializeState_WithNonEmptyArray_ReturnsTrue) {
        ProgramState* programState = ProgramState::getInstance();
        std::array<Hex4digit, ProgramState::TOTAL_MEMORY_SPACES> nonEmptyInstructions;
        nonEmptyInstructions[0] = Hex4digit(0x0001);

        bool result = programState->initializeState(nonEmptyInstructions);

        Assert::IsTrue(result);
    }

    // Test clearProgramState() method
    TEST_METHOD(ClearProgramState_RegistersAndHistoryCleared) {
        ProgramState* programState = ProgramState::getInstance();
        std::array<Hex4digit, ProgramState::TOTAL_MEMORY_SPACES> nonEmptyInstructions;
        nonEmptyInstructions[0] = Hex4digit(0x0001);
        programState->initializeState(nonEmptyInstructions);

        programState->clearProgramState();

        Assert::AreEqual((Hex4digit)0, programState->getMemoryStateValue(0));
        Assert::AreEqual((Hex4digit)0, programState->registers[0]);
        Assert::AreEqual((Hex4digit)0, programState->registers.back());
    }

    // Test printableProgramState() method with zero memory state
    TEST_METHOD(PrintableProgramState_WithZeroMemoryState_CorrectOutput) {
        ProgramState* programState = ProgramState::getInstance();
        std::array<Hex4digit, ProgramState::TOTAL_MEMORY_SPACES> zeroInstructions;
        programState->initializeState(zeroInstructions);

        std::string result = programState->printableProgramState();

        Assert::IsFalse(result.find("Next:") != std::string::npos);
    }

    // Test printableProgramState() method with non-zero memory state
    TEST_METHOD(PrintableProgramState_WithNonZeroMemoryState_CorrectOutput) {
        ProgramState* programState = ProgramState::getInstance();
        std::array<Hex4digit, ProgramState::TOTAL_MEMORY_SPACES> nonEmptyInstructions;
        nonEmptyInstructions[0] = Hex4digit(0x0001);
        programState->initializeState(nonEmptyInstructions);

        std::string result = programState->printableProgramState();

        Assert::IsTrue(result.find("Next:") != std::string::npos);
    }

    TEST_METHOD(getMemoryStateValue) {

    }
};

TEST_CLASS(FileManagerTests) {
    //TODO

};
}
