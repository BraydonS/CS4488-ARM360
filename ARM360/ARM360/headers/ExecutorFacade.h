
#pragma once
#include <string>
#include "ProgramState/ProgramState.h"
#include "InstructionSet.h"
#include "Hex4digit.h"

class ExecutorFacade{

    public: 
        int MEMORYSTATEINDEX;
        std::string EXCEPTIONMESSAGE;

        int getMemoryStateIndex();

        //int getMemoryIndex();

        void incrementMemoryIndex();

        bool next();

        bool hasNext();

        void setProgramState(ProgramState state);

        bool hasState();

        void clearState();

        std::string getLastExceptionMessage();


    private: 
        void updatePCHistory();

        void determineInstruction(Hex4digit instance);

        void unrecognizedInstruction(ProgramState state);
};