// Main entry point for the test.
#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/ProgramState/ProgramState.h"
#include "../../ARM360/headers/FileManager/FileManager.h"
#include "../../ARM360/headers/Hex4digit.h"
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test { 

    TEST_CLASS(ProgramStateTests) {

public:

    // Test initializeState() method with empty array of instructions
    TEST_METHOD(InitializeState_WithEmptyArray_ReturnsFalse) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> emptyInstructions;

        bool result = programState->initializeState(emptyInstructions);

        Assert::IsFalse(result);
        programState->clearProgramState();
    }

    // Test initializeState() method with non-empty array of instructions
    TEST_METHOD(InitializeState_WithNonEmptyArray_ReturnsTrue) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> nonEmptyInstructions;
        nonEmptyInstructions[0] = Hex4digit(0x0001);

        bool result = programState->initializeState(nonEmptyInstructions);

        Assert::IsTrue(result);
        programState->clearProgramState();
    }

    // Test clearProgramState() method
    TEST_METHOD(ClearProgramState_RegistersAndHistoryCleared) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> nonEmptyInstructions;
        nonEmptyInstructions[0] = Hex4digit(0x0001);
        programState->initializeState(nonEmptyInstructions);

        programState->clearProgramState();

        Assert::AreEqual((Hex4digit)0, programState->getMemoryStateValue(0));
        Assert::AreEqual((Hex4digit)0, programState->registers[0]);
        Assert::AreEqual((Hex4digit)0, programState->registers.back());
        programState->clearProgramState();
    }

    // Test printableProgramState() method with zero memory state
    TEST_METHOD(PrintableProgramState_WithZeroMemoryState) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> zeroInstructions;
        programState->initializeState(zeroInstructions);

        std::string result = programState->printableProgramState();

        Assert::IsFalse(result.find("Next:") != std::string::npos);
        programState->clearProgramState();
    }

    // Test printableProgramState() method with non-zero memory state
    TEST_METHOD(PrintableProgramState_WithNonZeroMemoryState) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> nonEmptyInstructions;
        nonEmptyInstructions[0] = Hex4digit(0x0001);
        programState->initializeState(nonEmptyInstructions);

        std::string result = programState->printableProgramState();

        Assert::IsTrue(result.find("Next:") != std::string::npos);
        programState->clearProgramState();
    }

    TEST_METHOD(getMemoryStateValue) {
        ProgramState* programState = ProgramState::getInstance();
        std::vector<Hex4digit> nonEmptyInstructions;
        nonEmptyInstructions[0] = Hex4digit(0x0001);
        programState->initializeState(nonEmptyInstructions);

        Hex4digit testVal = Hex4digit(0x0001);

        Assert::AreEqual(programState->getMemoryStateValue(0), testVal);
        
        programState->clearProgramState();
    }
};

TEST_CLASS(FileManagerTests) {
    
    TEST_METHOD(CheckFile_FileDoesntExist) {
        std::string invalidPath = "/invalid/path";

        FileManager* fileManager = FileManager::getInstance();

        bool fileIsValid = fileManager->checkFile(invalidPath);

        Assert::IsFalse(fileIsValid);
    }

    TEST_METHOD(CheckFile_FileDoesExist) {
        std::string validPath = "test.txt";

        std::ofstream testFile(validPath.c_str());

        testFile.close();

        FileManager* fileManager = FileManager::getInstance();

        bool fileIsValid = fileManager->checkFile(validPath);

        Assert::IsTrue(fileIsValid);

        std::remove(validPath.c_str());
    }

    TEST_METHOD(ReadFile_ValidFile) {
        std::string filePath = "test.txt";
        std::string testString = "test";

        //Write to test file
        std::ofstream testFile(filePath.c_str());
        testFile << testString;
        testFile.close();

        FileManager* fileManager = FileManager::getInstance();

        // Read and assert contents are equal
        std::string fileContents = fileManager->readFile(filePath);

        Assert::AreEqual(fileContents, testString);

        std::remove(filePath.c_str());
    }

    TEST_METHOD(ReadFile_InvalidFile) {

        std::string invalidPath = "/invalid/path";
        std::string testString;

        FileManager* fileManager = FileManager::getInstance();

        // Read and assert contents are equal
        std::string fileContents = fileManager->readFile(invalidPath);

        Assert::AreEqual(fileContents, testString);
    }

    TEST_METHOD(WriteFile_Success) {

        std::string validPath = "test.txt";
        std::string testString = "test";

        FileManager* fileManager = FileManager::getInstance();

        
        bool writeSuccess = fileManager->writeFile(validPath,testString);


        std::ifstream testFileStream("test.txt");
        std::string testFileContent((std::istreambuf_iterator<char>(testFileStream)),
            (std::istreambuf_iterator<char>()));

        Assert::IsTrue(writeSuccess);
        Assert::AreEqual(testFileContent, testString);
    }

    TEST_METHOD(WriteFile_Failure) {

        std::string validPath = "test.badtype";
        std::string testString = "test";

        FileManager* fileManager = FileManager::getInstance();


        bool writeSuccess = fileManager->writeFile(validPath, testString);

        Assert::IsFalse(writeSuccess);
    }
};
}