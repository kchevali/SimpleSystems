#include "../hardware/bit.h"
#include "../hardware/computer.h"
#include "../hardware/int.h"
#include "../hardware/ram4k.h"

int main() {
  RAM4k ram = RAM4k();
  Computer comp = Computer(ram);
  comp.readFileToRAM();
  comp.run();
}