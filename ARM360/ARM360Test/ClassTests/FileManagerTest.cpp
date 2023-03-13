#include "pch.h"
#include "CppUnitTest.h"
#include "../../ARM360/headers/FileManager/FileManager.h"
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARM360Test {
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


            bool writeSuccess = fileManager->writeFile(validPath, testString);


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


