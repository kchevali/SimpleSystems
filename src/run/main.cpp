#include <iostream>

#include "../hardware/bit.h"
#include "../hardware/computer.h"
#include "../hardware/int.h"
#include "../hardware/ram64.h"

Int Hardware::hardwareCounter = 0;
int main() {
  RAM64 ram = RAM64();
  Computer comp = Computer(ram);
  comp.readFileToRAM();
  comp.run();
}