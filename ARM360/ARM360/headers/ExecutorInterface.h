// ExecutorInterface Header file
// Show Pratoomratana
// 01/27/23

// .h file for development so the IDE can reconize the classes we have yet to implement.
#pragma once
#include "stdafx.h"
#include <string>

/*
Originally a interface, but .h files effectly function as interfaces. So this made more sense.
*/
class ExecutorInterface{

    public: 
        void setProgramState(/*ProgramState state*/);

        bool hasState();

        bool next();

        bool hasNext();

        void clearState();
        
        std::string getLastExceptionMessage();
};