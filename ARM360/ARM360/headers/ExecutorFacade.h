
#pragma once
#include <string>
#include <ProgramState/ProgramState.h>
#include <Hex4digit.h>
// .h file for development so the IDE can reconize the classes we have yet to implement.

class ExecutorFacade{

    public: 
        int getMemoryIndex(){}

        int incrementMemoryIndex(){}

        bool next(){}

        bool hasNext(){}

        void clearState(){}

        std::string getLastExceptionMessage(){}


    private: 
        void updatePCHistory(){}

        private: void determineInstruction(Hex4digit instance){}

        void unrecognizedInstruction(ProgramState state){}
};