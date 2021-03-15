#include "ram.h"
#include "int.h"
#include <iostream>
RAM::RAM(Int capacity) { this->capacity = capacity; }

// update(Int in, Bit load, Int address)
void RAM::update(Int& dataBus, Int& addressBus, Int& controlBus) {
  Bit isDestM = controlBus[ML];
  Bit isLoad = isDestM & controlBus[LOAD];
  Bit isConst = isDestM & controlBus[CONST];
  std::cout << "MEM | isDestM: " << isDestM << " isLoad: " << isLoad
            << " isConst: " << isConst << "\n";

  // possibly insert data to mem[addr] and read current content
  Int out = update(dataBus, isLoad, addressBus);
  std::cout << "MEM UPDATE - M[" << hex(addressBus) << "] = " << hex(out)
            << "\n";

  Bit isOutputData = isDestM & controlBus[DATA];
  Bit isOutputAddress = isDestM & controlBus[ADDR] & (~isConst);
  Bit isOutputControl = isDestM & controlBus[CONTROL];

  dataBus = isOutputData.mux(dataBus, out);
  // addressBus = isOutputAddress.mux(addressBus, out);
  // controlBus = isOutputControl.mux(controlBus, out);

  Int newAddress, newControl;
  decode(out, newAddress, newControl);
  addressBus = isOutputAddress.mux(addressBus, newAddress);
  controlBus = isOutputControl.mux(controlBus, newControl);
  std::cout << "MEM OUTPUTS -  DATA: " << hex(dataBus)
            << " ADDR:" << hex(addressBus) << " CONTROL: " << hex(controlBus)
            << "\n";
}
