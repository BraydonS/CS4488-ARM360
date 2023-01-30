<<<<<<< HEAD
// ExecutorFacade Header file
// Show Pratoomratana
// 01/27/23

=======

#pragma once
>>>>>>> 5202c205fea8e71e36963cf257b8b439ebff4f5d
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