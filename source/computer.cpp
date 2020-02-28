#include "computer.h"
#include <fstream>
#include <iostream>
#include "controller.h"
#include "cpu.h"
#include "pc.h"
#include "ram.h"

Computer::Computer(RAM& ram) : ram(ram), pc(), cpu(), controller(*this) {
  //   this->ram = ram;
  // this->pc = PC();
  // this->cpu = CPU();
  // this->controller = Controller(*this);

  this->dataBus = 0;
  this->addressBus = 0;
  this->controlBus = 0;
}

void Computer::run() { controller.run(); }

void Computer::update() {
  updatePC();
  updateCPU();
  updateRAM();
  updateController();
}

void Computer::updatePC() { pc.update(dataBus, addressBus, controlBus); }
void Computer::updateCPU() { cpu.update(dataBus, addressBus, controlBus); }
void Computer::updateController() {
  controller.update(dataBus, addressBus, controlBus);
}
void Computer::updateRAM() { ram.update(dataBus, addressBus, controlBus); }

void Computer::setDataBus(Int& bits) { dataBus = bits; }
void Computer::setAddressBus(Int& bits) { addressBus = bits; }
void Computer::setControlBus(Int& bits) { controlBus = bits; }

void Computer::readFileToRAM() {
  std::ifstream in("../files/file.txt");
  std::string line;
  for (Int address = 0; in.good(); ++address) {
    in >> line;
    // update(Int in, Bit load, Int address)
    ram.update(Int(stoi(line, 0, 2)), 1, address);
  }
  in.close();
}