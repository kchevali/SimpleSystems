#ifndef COMPUTER_H
#define COMPUTER_H

#include "controller.h"
#include "cpu.h"
#include "hardware.h"
#include "pc.h"
#include "ram.h"

class Computer {
 public:
  Computer(RAM& ram);
  void run();
  void update();
  void updatePC();
  void updateCPU();
  void updateController();
  void updateRAM();
  void setDataBus(Int& bits);
  void setAddressBus(Int& bits);
  void setControlBus(Int& bits);
  void readFileToRAM();
  Int dataBus, addressBus, controlBus;

 private:
  RAM& ram;
  PC pc;
  CPU cpu;
  Controller controller;
};

#endif