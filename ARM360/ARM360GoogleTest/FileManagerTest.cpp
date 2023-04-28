#include "pch.h"
#include "../../ARM360/headers/FileManager/FileManager.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace ARM360Test {
    class FileManagerTests : public ::testing::Test {
    protected:
        void SetUp() override {
            // Code executed before each test case
        }

        void TearDown() override {
            // Code executed after each test case
        }

        // Declare any variables or pointers you want to use in multiple tests
        FileManager* fileManager = FileManager::getInstance();
        string filePath = "test.txt";
        string testString = "test";
    };

    TEST_F(FileManagerTests, CheckFile_FileDoesntExist) {
        string invalidPath = "/invalid/path";
        bool fileIsValid = fileManager->checkFile(invalidPath);
        EXPECT_FALSE(fileIsValid);
    }

    TEST_F(FileManagerTests, CheckFile_FileDoesExist) {
        ofstream testFile(filePath.c_str());
        testFile.close();

        bool fileIsValid = fileManager->checkFile(filePath);
        EXPECT_TRUE(fileIsValid);

        remove(filePath.c_str());
    }

    TEST_F(FileManagerTests, ReadFile_ValidFile) {
        //Write to test file
        ofstream testFile(filePath.c_str());
        testFile << testString;
        testFile.close();

        // Read and assert contents are equal
        string fileContents = fileManager->readFile(filePath);
        EXPECT_EQ(fileContents, testString);

        remove(filePath.c_str());
    }

    TEST_F(FileManagerTests, ReadFile_InvalidFile) {
        string invalidPath = "/invalid/path";
        string testString;

        // Read and assert contents are equal
        string fileContents = fileManager->readFile(invalidPath);
        EXPECT_EQ(fileContents, testString);
    }

    TEST_F(FileManagerTests, WriteFile_Success) {
        bool writeSuccess = fileManager->writeFile(filePath, testString);

        ifstream testFileStream(filePath);
        string testFileContent((istreambuf_iterator<char>(testFileStream)), (istreambuf_iterator<char>()));

        EXPECT_TRUE(writeSuccess);
        EXPECT_EQ(testFileContent, testString);

        remove(filePath.c_str());
    }

    TEST_F(FileManagerTests, WriteFile_Failure) {
        string invalidPath = "test.badtype";
        string testString = "test";

        bool writeSuccess = fileManager->writeFile(invalidPath, testString);
        EXPECT_FALSE(writeSuccess);
    }
}
