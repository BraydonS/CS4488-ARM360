#include "stdafx.h"
#include "MemoryHistorySpace.h"


MemoryHistorySpace::MemoryHistorySpace() : value(Hex4digit()), memoryLocation(0) {}
int MemoryHistorySpace::getMemoryLocation() {
	return this->memoryLocation;
}
void MemoryHistorySpace::setMemoryLocation(int mem) {
	this->memoryLocation = mem;
}
Hex4digit MemoryHistorySpace::getValue() {
	return this->value;
}
void MemoryHistorySpace::setValue(Hex4digit val) {
	this->value = val;
}

