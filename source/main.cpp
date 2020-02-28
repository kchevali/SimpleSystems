#include <iostream>
#include "bit.h"
#include "computer.h"
#include "int.h"
#include "ram64.h"

Int Hardware::hardwareCounter = 0;
int main() {
  RAM64 ram = RAM64();
  Computer comp = Computer(ram);
  comp.readFileToRAM();
  comp.run();
}