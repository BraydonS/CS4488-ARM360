// ExecutorFacade source file
// Show Pratoomratana
// 02/01/2023
#include <string>
#include "stdafx.h"
#include "ExecutorFacade.h"

// Global variables
int MEMORYSTATEINDEX = 0;
std::string EXCEPTIONMESSAGE = "No Error";

// Private methods

// Updates index of current memory is being accessed.
void ExecutorFacade::incrementMemoryIndex() {
    MEMORYSTATEINDEX++;
}
// Updates the program counter with the last memory location.
void ExecutorFacade::updatePCHistory(){                                             
    MemoryHistorySpace pc = MemoryHistorySpace();
    pc.setMemoryLocation(MEMORYSTATEINDEX);
    ProgramState::getInstance()->pcHistory.push_back(pc);
}

//Public methods
int ExecutorFacade::getMemoryStateIndex(){
    return MEMORYSTATEINDEX;
}

// Function to check if the next instruction goes out of bounds.
// @return bool : whether or not the next instruction is valid.
bool ExecutorFacade::hasNext(){

    // The current value and size of the Program Counter respecivly. 
    int programStateValue = ProgramState::getInstance()->registers[15].getValue();
    int programStateSize = ProgramState::getInstance()->memoryStateHistory.at(MEMORYSTATEINDEX).size();

    // If the Counter Count is >= to the length of memory list,then it's gone past the program memory.
    if(programStateValue >= programStateSize) {
        EXCEPTIONMESSAGE = "Program Counter tried to access memory out of bounds";
        return false;
    }

    // Program Counter contains an error, -1, halt.
    if(programStateValue == -1) {
        EXCEPTIONMESSAGE = "A halt command was executed and the program has stopped";
        return false;
    }

    // Program Counter tries to access negative memory.
    if(programStateValue < -1) {
        EXCEPTIONMESSAGE = "Program Counter tried to index negative memory";
        return false;
    }

    return true;
}

// Function to Simply creates the current program state with an empty vector.
void ExecutorFacade::setProgramState(ProgramState state){
    std::array<Hex4digit, ProgramState::TOTAL_MEMORY_SPACES> code;
    state.initializeState(code);
}

// Simply checks if the state of the program is empty or not.
// @return bool: whether or not a memorystatehistory currently exists.
bool ExecutorFacade::hasState() {
    if (ProgramState::getInstance()->memoryStateHistory.empty()){
        EXCEPTIONMESSAGE = "No state has been created";
        return false;
    }
    return true;
}

// If the given programState is unknown update the exceptionMessage.
// @param : The current programState
void ExecutorFacade::unrecognizedInstruction(ProgramState state) {
    EXCEPTIONMESSAGE = "The given instruction was not recognized!";
    InstructionSet::halt(state);
}

// Takes a hex instruction based on the first value and executes the corresponding instruction.
// @param : The current object instance of the Hex4digit class.
void ExecutorFacade::determineInstruction(Hex4digit instance){
    ProgramState *state = ProgramState::getInstance();
    switch(instance.getHexChars()[1]){
        case '0': InstructionSet::halt(*state); break;
        case '1': InstructionSet::load(*state, instance.getMiddle2Value(), instance.getHexChars()[4], MEMORYSTATEINDEX); break;
        case '2': InstructionSet::store(*state, instance.getMiddle2Value(), instance.getHexChars()[4], MEMORYSTATEINDEX); break;
        case '3': InstructionSet::add(*state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]); break;
        case '4': InstructionSet::subt(*state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]); break;
        case '5': InstructionSet::mult(*state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]); break;
        case '6': InstructionSet::intDivide(*state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]); break;
        case '7': InstructionSet::loadIndirect(*state, instance.getMiddle2Value(), instance.getHexChars()[4], MEMORYSTATEINDEX); break;
        case '8': InstructionSet::storeIndirect(*state, instance.getMiddle2Value(), instance.getHexChars()[4], MEMORYSTATEINDEX); break;
        case '9': InstructionSet::branch(*state, instance.getMiddle2Value()); break;
        case 'a': InstructionSet::branchZero(*state, instance.getHexChars()[2], instance.getLast2Value()); break;
        case 'b': InstructionSet::branchNeg(*state, instance.getHexChars()[2], instance.getLast2Value()); break;
        case 'c': InstructionSet::branchPos(*state, instance.getHexChars()[2], instance.getLast2Value()); break;
        case 'd': InstructionSet::readInt(*state, instance.getHexChars()[2]); break;
        case 'e': InstructionSet::writeInt(*state, instance.getHexChars()[2]); break;
        case 'f': InstructionSet::skip(*state); break;
        default:  unrecognizedInstruction(*state);
        }
}

// Function to execute the next instruction and update the memory index.
// @return bool : Whether or not the execution was successfull.
bool ExecutorFacade::next(){
    // Check if the programState is instantiated. 
    // and check if there's already a instruction in the program counter.
    if (!hasState() || !hasNext()){
        return false;
    }

    // The next instruction to be executed is indexed by the Program Counter.
    // E.G If Register 15 has the value 7, index 7 in the memorystatehistory will be executed.
    Hex4digit instruction = ProgramState::getInstance()
                            ->memoryStateHistory.at(MEMORYSTATEINDEX)
                            .at(ProgramState::getInstance()->registers[15].getValue());
    
    // Get the instruction and update the history and memory index.
    determineInstruction(instruction);
    updatePCHistory();
    incrementMemoryIndex();

    // Copy over the memory vector to the next index in the list.
    std::vector<std::array<Hex4digit, ProgramState::TOTAL_MEMORY_SPACES>> memState = ProgramState::getInstance()->memoryStateHistory;
    memState.insert(memState.begin() + MEMORYSTATEINDEX, 
                    ProgramState::getInstance()->memoryStateHistory.at(MEMORYSTATEINDEX - 1));
    
    return true;
}

// Clears the current state of the programState.
void ExecutorFacade::clearState(){
    MEMORYSTATEINDEX = 0;
    ProgramState::getInstance()->clearProgramState();
}

// Simply gets the last exceptionMessage from the program.
// @return string: string of last exception message.
std::string ExecutorFacade::getLastExceptionMessage(){
    return EXCEPTIONMESSAGE;
}
