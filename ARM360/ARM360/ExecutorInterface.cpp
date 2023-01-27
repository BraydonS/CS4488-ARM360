#include "stdafx.h"
#include <string>

class ExecutorInterface{

    // public: 
    //    virtual void setProgramState(ProgramState state) = 0;

    public:
        virtual bool hasState() = 0;

    public: 
        virtual bool next() = 0;

    public: 
        virtual bool hasNext() = 0;

    public: 
        virtual void clearState() = 0;

    public: 
        virtual std::string getLastExceptionMessage() = 0;
};