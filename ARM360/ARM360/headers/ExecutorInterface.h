#include "stdafx.h"
#include <string>

/*
Originally a interface, but .h files effectly function as interfaces. So this made more sense.
*/
class ExecutorInterface{

    public: void setProgramState(/*ProgramState state*/);

    public: bool hasState();

    public: bool next();

    public: bool hasNext();

    public: void clearState();

    public: std::string getLastExceptionMessage();
};