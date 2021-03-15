

#include "os.h"

#include "computer.h"

OS::OS(Computer& computer) : computer(computer) {}

void OS::loadConst(Int value) const {}
void OS::halt() const {}
