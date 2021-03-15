#include "pc.h"
#include "bit.h"
#include "int.h"
#include <iostream>

PC::PC() { counter = Register(); }

void PC::update(Int& dataBus, Int& addressBus, Int& controlBus) {
  Bit isDestPC = controlBus[PCL];
  Bit isLoad = isDestPC & controlBus[LOAD];
  Bit isInc = isDestPC & controlBus[INC];
  Bit isJMP = isDestPC & controlBus[JMP];
  Bit isJNZ = isDestPC & controlBus[JNZ];
  // Bit isJLT = isDestPC & controlBus[JLT];
  // Bit isJGT = isDestPC & controlBus[JGT];
  // Bit isJLE = isDestPC & controlBus[JLE];
  // Bit isJGE = isDestPC & controlBus[JGE];

  Bit isZero = isDestPC & (~(dataBus.or32Way()));
  Bit isJump = isDestPC & ((isJNZ && isZero) | isJMP);
  Bit isReset = isDestPC & (~(controlBus.or32Way()));

  counter.update(counter.update(0, isReset) + 1, isInc);
  counter.update(addressBus, isJump);

  Int out = counter.update(dataBus, isLoad);

  Bit isOutputData = isDestPC & controlBus[DATA];
  Bit isOutputAddress = isDestPC & controlBus[ADDR];
  Bit isOutputControl = isDestPC & controlBus[CONTROL];

  std::cout << "PC | isDestPC: " << isDestPC << "isData:" << isOutputData
            << " isAddress: " << isOutputAddress
            << " isControl: " << isOutputControl << " isLoad: " << isLoad
            << " isInc: " << isInc << " isJMP: " << isJMP << " isJNZ: " << isJNZ
            << " isZero: " << isZero << " isJump: " << isJump
            << " isReset: " << isReset << " OUT: " << out << "\n";

  dataBus = isOutputData.mux(dataBus, out);
  addressBus = isOutputAddress.mux(addressBus, out);
  controlBus = isOutputControl.mux(controlBus, out);
  std::cout << "PC OUTPUTS -  DATA: " << hex(dataBus)
            << " ADDR:" << hex(addressBus) << " CONTROL: " << hex(controlBus)
            << "\n";
}