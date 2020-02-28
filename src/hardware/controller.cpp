

#include "controller.h"
#include <iostream>
#include "computer.h"
#include "int.h"

Controller::Controller(Computer& computer) : computer(computer) {
  this->isHalt = false;
}
void Controller::run() {
  Int maxLoopCount = 10;
  while ((!isHalt && (maxLoopCount -= 1) >= 0).getBool()) {
    std::cout << "\n====================\n";

    // READ PC -> ADDR BUS
    std::cout << "LOADING PC TO ADDRESS BUS\n";
    Int loadPC = encode(addressBit, destPC, NOP);
    computer.setControlBus(loadPC);
    computer.updatePC();

    // READ M  -> ADDR BUS + INST BUS
    std::cout << "LOADING MEM TO ADDRESS + CONTROL BUS\n";
    Int loadMem = encode(addressBit | controlBit, destM, NOP);
    computer.setControlBus(loadMem);
    computer.updateRAM();

    // EXEC
    std::cout << "EXECUTING\n";
    computer.update();

    // INC PC -> NONE
    std::cout << "INCREMENTING PC\n";
    Int incPC = encode(addressBit, destPC, INC);
    computer.setControlBus(incPC);
    computer.updatePC();
  }
}
void Controller::update(Int& dataBus, Int& addressBus, Int& controlBus) {
  Int code;
  decode(controlBus, code);
  isHalt = code == HALT;
  std::cout << "CONTROLLER UPDATE - HALT: " << isHalt << "\n";
}