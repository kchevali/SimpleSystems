

#include "controller.h"
#include "computer.h"
#include "int.h"
#include <iostream>

Controller::Controller(Computer& computer) : computer(computer) {
  this->isHalt = 0;
}
void Controller::run() {
  while ((!isHalt).getBool()) {
    std::cout << "\n====================\n";

    // READ PC -> ADDR BUS
    std::cout << "OUTPUTTING PC TO ADDRESS BUS\n";
    Int loadPC = Int(1 << PCL) | Int(1 << ADDR);
    computer.setControlBus(loadPC);
    computer.updatePC();

    // READ M  -> ADDR BUS + INST BUS
    std::cout << "\nOUTPUTTING MEM TO ADDRESS & CONTROL BUS\n";
    Int loadMem = Int(1 << ML) | Int(1 << ADDR) | Int(1 << CONTROL) | Int(LOAD);
    computer.setControlBus(loadMem);
    computer.updateRAM();

    // EXEC
    std::cout << "\nEXECUTING\n";
    computer.update();

    // INC PC -> NONE
    std::cout << "\nINCREMENTING PC\n";
    Int incPC = Int(1 << PCL) | Int(1 << ADDR) | Int(1 << INC);
    computer.setControlBus(incPC);
    computer.updatePC();
  }
}
void Controller::update(Int& dataBus, Int& addressBus, Int& controlBus) {
  isHalt = (~(addressBus.or32Way())) & (~(controlBus.or32Way()));
  std::cout << "CONTROLLER UPDATE - HALT: " << isHalt << "\n";
}