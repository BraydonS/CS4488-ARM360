#include "stdafx.h"
#include "Hex4Digit.h"


class MemoryHistorySpace {
public:
    Hex4digit value;
    int memoryLocation;
    MemoryHistorySpace() {
        value = Hex4digit();
        memoryLocation = 0;
    }
};
