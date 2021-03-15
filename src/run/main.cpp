#include "bit.h"
#include "computer.h"
#include "int.h"
#include "ram4k.h"

int main() {
  RAM4k ram = RAM4k();
  Computer comp = Computer(ram);
  comp.readFileToRAM();
  comp.run();
}