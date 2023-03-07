
#pragma once
#include "Hex4digit.h"

class MemoryHistorySpace {
private:
    Hex4digit value;
    int memoryLocation;
public:
    MemoryHistorySpace();
    int getMemoryLocation();
    void setMemoryLocation(int mem);
    Hex4digit getValue();
    void setValue(Hex4digit val);
};