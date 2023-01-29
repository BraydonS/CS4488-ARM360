// ExecutorFacade Class
// Show Pratoomratana
// 01/28/23
#include <string>
#include "ProgramState/programstate.h"
#include "InstructionSet.h"
//#include "headers/Hex4digit.h"

class ExecutorFacade{

    // Global variables
    int memoryStateIndex = 0;
    std::string exceptionMessage = "No Error";

    //Public methods
    public:
        int getMemoryStateIndex(){
            return memoryStateIndex;
        }

        /*bool next(){                                                                                                              // Update
            // Check if the programState is instantiated. 
            // and check if there's already a instruction in the program counter.
            if (!hasState() || !hasNext()){
                return false;
            }

            // The next instruction to be executed is indexed by the Program Counter.
            // E.G If Register 15 has the value 7, index 7 in the memoryStateHistory will be executed.
            Hex4Digit instruction = ProgramState::getInstance()
                                    .memoryStateHistory.get(memoryStateIndex)
                                    .get(ProgramState::getInstance().registers[15].getValue());
            
            // Get the instruction and update the history and memory index.
            determineInstruction(instruction);
            updatePCHistory();
            incrementMemoryIndex();

            // Copy over the memory vector to the next index in the list.
            ProgramState::getInstance().memoryStateHistory
            .add(MEMORYSTATEINDEX, ProgramState::getInstance().memoryStateHistory.get(memoryStateIndex - 1));
            
            return true;
        }*/

        /*bool hasNext(){

            // The current value and size of the Program Counter respecivly. 
            int programStateValue = ProgramState::getInstance().registers[15].getValue();
            int programStateSize = ProgramState::getInstance().memoryStateHistory.get(memoryStateIndex).size();

            // If the Counter Count is >= to the length of memory list,then it's gone past the program memory.
            if(programStateValue >= programStateSize) {
                exceptionMessage = "Program Counter tried to access memory out of bounds";
                return false;
            }

            // Program Counter contains an error, -1, halt.
            if(programStateValue == -1) {
                exceptionMessage = "A halt command was executed and the program has stopped";
                return false;
            }

            // Program Counter tries to access negative memory.
            if(programStateValue < -1) {
                exceptionMessage = "Program Counter tried to index negative memory";
                return false;
            }

            return false;
        }

        // Simply creates the current program state with an empty vector.
        void setProgramState(ProgramState state){
            std::vector<Hex4digit> code;
            state.initializeState(code);
        }

        // Simply checks if the state of the program is empty or not.
        bool hasState() {
            if (ProgramState::getInstance().memoryStateHistory.isEmpty()){
                exceptionMessage = "No state has been created";
                return false;
            }
            return true;
        }*/

        void clearState(){
            memoryStateIndex = 0;
            ProgramState::getInstance().clearProgramState();
        }

        std::string getLastExeptionMessage(){
            return exceptionMessage;
        }

    // Private methods
    private: 

        // Updates index of current memory is being accessed.
        void incrementMemoryIndex() {
            memoryStateIndex++;
        }
        // Updates the program counter with the last memory location.
        /*void updatePCHistory(){                                                                                                   // Update                                              
            MemoryHistorySpace pc = new MemoryHistorySpace();
            pc.memoryLocation = memoryStateIndex;
            ProgramState::getInstance().pcHistory.add(pc);
        }

        // Takes a hex instruction based on the first value and executes the corresponding instruction.
        void determineInstruction(hex4Digit instance){
            ProgramState state = ProgramState::getInstance();
            switch(instance.getHexChars()[1]){
                case "0": InstructionSet::halt(state);
                case "1": InstructionSet::load(state, instance.getMiddle2Value(), instance.getHexChars()[4], memoryStateIndex);
                case "2": InstructionSet::store(state, instance.getMiddle2Value(), instance.getHexChars()[4], memoryStateIndex);
                case "3": InstructionSet::add(state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]);
                case "4": InstructionSet::subt(state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]);
                case "5": InstructionSet::mult(state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]);
                case "6": InstructionSet::intDivide(state, instance.getHexChars()[2], instance.getHexChars()[3], instance.getHexChars()[4]);
                case "7": InstructionSet::loadIndirect(state, instance.getMiddle2Value(), instance.getHexChars()[4], memoryStateIndex);
                case "8": InstructionSet::storeIndirect(state, instance.getMiddle2Value(), instance.getHexChars()[4], memoryStateIndex);
                case "9": InstructionSet::branch(state, instance.getMiddle2Value());
                case "a": InstructionSet::branchZero(state, instance.getHexChars()[2], instance.getLast2Value());
                case "b": InstructionSet::branchNeg(state, instance.getHexChars()[2], instance.getLast2Value());
                case "c": InstructionSet::branchPos(state, instance.getHexChars()[2], instance.getLast2Value());
                case "d": InstructionSet::readInt(state, instance.getHexChars()[2]);
                case "e": InstructionSet::writeInt(state, instance.getHexChars()[2]);
                case "f": InstructionSet::skip(state);
                default:  unrecognizedInstruction(state);
                }
        }

    void unrecognizedInstruction(ProgramState state) {
        exceptionMessage = "The given instruction was not recognized!";
        InstructionSet::halt(state);
    }*/
};