// ExecutorFacade Header file
// Show Pratoomratana
// 01/27/23

#include <string>
//#include <ProgramState.h>
//#include <Hex4digit.h>
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

        //Commented out until we implement Hex 4digit
        //private: void determineInstruction(Hex4digit instance){}

        //Commented out parameters until we implement programState
        void unrecognizedInstruction(/*programState state*/){}
};