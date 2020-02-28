#include "register.h"
#include "bit.h"
#include "int.h"

Register::Register() { this->mem = 0; }
Int Register::update(Int in, Bit load) { return mem = load.mux(mem, in); }
Int Register::read() { return update(0, 0); }