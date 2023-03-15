#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/Hex4digit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test {

    TEST_CLASS(ProgramStateTests) {

public:

    // Test initializeState() method with empty array of instructions
    TEST_METHOD(InitializeState_WithEmptyArray_ReturnsFalse) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> emptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);

        bool result = programState->initializeState(emptyInstructions);

        Assert::IsFalse(result);
        programState->clearProgramState();
    }

    // Test initializeState() method with non-empty array of instructions
    TEST_METHOD(InitializeState_WithNonEmptyArray_ReturnsTrue) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> nonEmptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);
        nonEmptyInstructions[0] = Hex4digit(0x0001);

        bool result = programState->initializeState(nonEmptyInstructions);

        Assert::IsTrue(result);
        programState->clearProgramState();
    }

    // Test clearProgramState() method
    TEST_METHOD(ClearProgramState_RegistersAndHistoryCleared) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> nonEmptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);
        nonEmptyInstructions[0] = Hex4digit(0x0001);
        programState->initializeState(nonEmptyInstructions);

        programState->clearProgramState();

        Hex4digit zeroHex = Hex4digit(0);

        Assert::AreEqual(zeroHex.getValue(), programState->getMemoryStateValue(0).getValue());
        Assert::AreEqual(zeroHex.getValue(), programState->registers[0].getValue());
        Assert::AreEqual(zeroHex.getValue(), programState->registers.back().getValue());
        programState->clearProgramState();
    }

    // Test printableProgramState() method with zero memory state
    TEST_METHOD(PrintableProgramState_WithZeroMemoryState) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> zeroInstructions(ProgramState::TOTAL_MEMORY_SPACES);
        programState->initializeState(zeroInstructions);

        std::string result = programState->printableProgramState();

        Assert::IsFalse(result.find("Next:") != std::string::npos);
        programState->clearProgramState();
    }

    // Test printableProgramState() method with non-zero memory state
    TEST_METHOD(PrintableProgramState_WithNonZeroMemoryState) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> nonEmptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);
        nonEmptyInstructions[0] = Hex4digit(0x0001);
        programState->initializeState(nonEmptyInstructions);

        std::string result = programState->printableProgramState();

        Assert::IsTrue(result.find("Next:") != std::string::npos);
        programState->clearProgramState();
    }

    TEST_METHOD(getMemoryStateValue) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> nonEmptyInstructions(ProgramState::TOTAL_MEMORY_SPACES);
        nonEmptyInstructions[0] = Hex4digit(0x0001);
        programState->initializeState(nonEmptyInstructions);

        Hex4digit testVal = Hex4digit(0x0001);

        Assert::AreEqual(programState->getMemoryStateValue(0).getValue(), testVal.getValue());

        programState->clearProgramState();
    }
    };
}