// ExecutorFacade source file
// Show Pratoomratana
// 02/01/2023
#include "stdafx.h"
#include "ExecutorFacade.h"

// Global variables
int MEMORYSTATEINDEX = 0;
std::string EXCEPTIONMESSAGE = "No Error";

// Private methods

/// <summary>
/// Updates index of current memory is being accessed.
/// </summary>
void ExecutorFacade::incrementMemoryIndex() {
    MEMORYSTATEINDEX++;
}

/// <summary>
/// Updates the program counter with the last memory location.
/// </summary>
void ExecutorFacade::updatePCHistory(){                                             
    MemoryHistorySpace pc = MemoryHistorySpace();
    pc.setMemoryLocation(MEMORYSTATEINDEX);
    ProgramState::getInstance()->pcHistory.push_back(pc);
}

//Public methods

/// <summary>
/// Getter for the MemoryStateIndex
/// </summary>
/// <returns>MemoryStateIndex</returns>
int ExecutorFacade::getMemoryStateIndex(){
    return MEMORYSTATEINDEX;
}

/// <summary>
/// Function to check if the next instruction goes out of bounds.
/// </summary>
/// <returns>bool : whether or not the next instruction is valid.</returns>
bool ExecutorFacade::hasNext(){
    // The current value and size of the Program Counter respectivly. 
    int programStateValue = ProgramState::getInstance()->registers[15].getValue();
    int test0 = ProgramState::getInstance()->registers[0].getValue();
    int test1 = ProgramState::getInstance()->registers[1].getValue();
    int test2 = ProgramState::getInstance()->registers[2].getValue();
    int test3 = ProgramState::getInstance()->registers[3].getValue();
    int test4 = ProgramState::getInstance()->registers[4].getValue();
    int test5 = ProgramState::getInstance()->registers[5].getValue();
    int test6 = ProgramState::getInstance()->registers[6].getValue();
    int test7 = ProgramState::getInstance()->registers[7].getValue();
    int test8 = ProgramState::getInstance()->registers[8].getValue();
    int test9 = ProgramState::getInstance()->registers[9].getValue();
    int test10 = ProgramState::getInstance()->registers[10].getValue();
    int test11 = ProgramState::getInstance()->registers[11].getValue();
    int test12 = ProgramState::getInstance()->registers[12].getValue();
    int test13 = ProgramState::getInstance()->registers[13].getValue();
    int test14 = ProgramState::getInstance()->registers[14].getValue();
    int test15 = ProgramState::getInstance()->registers[15].getValue();


    int programStateSize = ProgramState::getInstance()->memoryStateHistory.at(MEMORYSTATEINDEX).size();

    // If the Counter Count is >= to the length of memory list,then it's gone past the program memory.
        if (programStateValue >= programStateSize){
            EXCEPTIONMESSAGE = "Program Counter tried to access memory out of bounds";
            return false;
        }

        // Program Counter contains an error, -1, halt.
        if (programStateValue == -1) {
            EXCEPTIONMESSAGE = "A halt command was executed and the program has stopped";
            return false;
        }

        if (programStateValue < -1) {
            EXCEPTIONMESSAGE = "Program Counter tried to index negative memory";
            return false;
        }

    return true;
}

/// <summary>
/// Function that simply creates the current program state with an empty vector.
/// </summary>
/// <param name="state">The ProgramState being initilized</param>
void ExecutorFacade::setProgramState(ProgramState state){
    std::vector<Hex4digit> code;
    state.initializeState(code);
}

/// <summary>
/// Simply checks if the state of the program is empty or not.
/// </summary>
/// <returns>bool: whether or not a memorystatehistory currently exists.</returns>
bool ExecutorFacade::hasState() {
    if (ProgramState::getInstance()->memoryStateHistory.empty()){
        EXCEPTIONMESSAGE = "No state has been created";
        return false;
    }
    return true;
}

/// <summary>
/// If the given programState is unknown update the exceptionMessage.
/// </summary>
/// <param name="state">The current programState</param>
void ExecutorFacade::unrecognizedInstruction(ProgramState state) {
    EXCEPTIONMESSAGE = "The given instruction was not recognized!";
    InstructionSet::halt(&state);
}

/// <summary>
/// Takes a hex instruction based on the first value and executes the corresponding instruction.
/// </summary>
/// <param name="instance">The current object instance of the Hex4digit class.</param>
void ExecutorFacade::determineInstruction(Hex4digit instance){
    ProgramState *state = ProgramState::getInstance();
    switch(instance.getHexChars()[1]){
        case '0': InstructionSet::halt(state); break;
        case '1': InstructionSet::load(state, instance.getMiddle2Value(), instance.getHexChars()[4], MEMORYSTATEINDEX); break;
        case '2': InstructionSet::store(state, instance.getMiddle2Value(), instance.getHexChars()[4], MEMORYSTATEINDEX); break;
        case '3': InstructionSet::add(state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]); break;
        case '4': InstructionSet::subt(state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]); break;
        case '5': InstructionSet::mult(state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]); break;
        case '6': InstructionSet::intDivide(state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]); break;
        case '7': InstructionSet::loadIndirect(state, instance.getMiddle2Value(), instance.getHexChars()[4], MEMORYSTATEINDEX); break;
        case '8': InstructionSet::storeIndirect(state, instance.getMiddle2Value(), instance.getHexChars()[4], MEMORYSTATEINDEX); break;
        case '9': InstructionSet::branch(state, instance.getMiddle2Value()); break;
        case 'a': InstructionSet::branchZero(state, instance.getHexChars()[2], instance.getLast2Value()); break;
        case 'b': InstructionSet::branchNeg(state, instance.getHexChars()[2], instance.getLast2Value()); break;
        case 'c': InstructionSet::branchPos(state, instance.getHexChars()[2], instance.getLast2Value()); break;
        case 'd': InstructionSet::readInt(state, instance.getHexChars()[2]); break;
        case 'e': InstructionSet::writeInt(state, instance.getHexChars()[2]); break;
        case 'f': InstructionSet::skip(state); break;
        default:  unrecognizedInstruction(*state);
        }
}

/// <summary>
/// Function to execute the next instruction and update the memory index.
/// </summary>
/// <returns>bool : Whether or not the execution was successfull.</returns>
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
    //std::vector<std::vector<Hex4digit>> memState = ProgramState::getInstance()->memoryStateHistory;
    ProgramState::getInstance()->memoryStateHistory.push_back(
        ProgramState::getInstance()->memoryStateHistory.at(MEMORYSTATEINDEX - 1));
    
    return true;
}

/// <summary>
/// Clears the current state of the programState.
/// </summary>
void ExecutorFacade::clearState(){
    MEMORYSTATEINDEX = 0;
    ProgramState::getInstance()->clearProgramState();
}

/// <summary>
/// Simply gets the last exceptionMessage from the program.
/// </summary>
/// <returns>string: string of last exception message.</returns>
std::string ExecutorFacade::getLastExceptionMessage(){
    return EXCEPTIONMESSAGE;
}
