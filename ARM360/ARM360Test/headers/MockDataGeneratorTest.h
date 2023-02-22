// Unit test header file for MockDataGenerator.cpp
#pragma once
#include "AutoTest.h"
#include "MockDataGenerator.h"
#include <QtTest>

class MockDataGeneratorTest: public QObject {
    Q_OBJECT

    private slots:
        // -- setup --
        //void init();

        // -- tests --
        void testGetRandomHexChar();
        
        void testGetRandomHexValue();

        void testGetRandomHexValue4();

        void testGetRandomHexChar5();

        void testGetJunkChar();

        void testGetJunkChar4();

};
