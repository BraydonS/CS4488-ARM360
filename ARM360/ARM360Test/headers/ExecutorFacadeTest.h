// Unit test header file for ExecutorFacadeTest.cpp
#pragma once
#include "AutoTest.h"
#include "ExecutorFacade.h"
#include <QtTest>

class ExecutorFacadeTest: public QObject {
    Q_OBJECT

    private slots:
        // -- setup --
        //void init();

        // -- tests --
        void testGetMemoryStateIndex();
        
        void testIncrementMemoryIndex();

        void testNext();

        void testSetProgramState();

        void testHasState();

        void testClearState();

        void testGetLastExceptionMessage();

        void testUpdatePCHistory();

        void testDetermineInstruction();

        void testUnrecognizedInstruction();

};