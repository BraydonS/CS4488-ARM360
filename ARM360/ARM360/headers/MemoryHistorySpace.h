//need to include package library tool

class MemoryHistorySpace {
public:
    Hex4digit value;
    int memoryLocation;
    MemoryHistorySpace() {
        value = Hex4digit();
        memoryLocation = 0;
    }
};