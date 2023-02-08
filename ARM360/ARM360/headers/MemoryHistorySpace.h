//need to include package library tool

#pragma once

class MemoryHistorySpace {
public:
    Hex4digit value;
    int memoryLocation;
    MemoryHistorySpace() {
        value = Hex4digit();
        memoryLocation = 0;
    }
};