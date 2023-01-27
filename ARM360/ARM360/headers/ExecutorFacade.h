#include <string>
//#include <ProgramState.h>
//#include <Hex4digit.h>

class ExecutorFacade{

public: int getMemoryIndex(){}

public: int incrementMemoryIndex(){}

private: void updatePCHistory(){}

//private: void determineInstruction(Hex4digit instance){}

public: bool next(){}

public: bool hasNext(){}

public: void clearState(){}

public: std::string getLastExceptionMessage(){}

private: void unrecognizedInstruction(/*programState state*/){}
};