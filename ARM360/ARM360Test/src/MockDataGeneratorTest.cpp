// Unit test class for MockDataGenerator.cpp
// This file is where the actual tests for MockDataGenerator.cpp will be written.
// To be filled out once all .cpp classes are impleneted.
// For a decent testing reference I used this example repo https://github.com/vivaladav/BitsOfBytes/tree/master/cpp-unit-testing-with-qt-test-introduction
#include "MockDataGeneratorTest.h"
#include "AutoTest.h"

// -- tests --
void MockDataGeneratorTest::testGetRandomHexChar(){
    // Just a sanity check to make sure the tests are set up correctly
    QVERIFY2(1 == 1, "getRandomHexChar is null");
}

void MockDataGeneratorTest::testGetRandomHexValue(){}

void MockDataGeneratorTest::testGetRandomHexValue4(){}

void MockDataGeneratorTest::testGetRandomHexChar5(){}

void MockDataGeneratorTest::testGetJunkChar(){}

void MockDataGeneratorTest::testGetJunkChar4(){}

//QTEST_APPLESS_MAIN(MockDataGeneratorTest)
DECLARE_TEST(MockDataGeneratorTest)