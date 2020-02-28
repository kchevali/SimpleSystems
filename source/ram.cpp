#include "ram.h"
#include <iostream>
#include "int.h"

RAM::RAM(Int capacity) { this->capacity = capacity; }

// update(Int in, Bit load, Int address)
void RAM::update(Int& dataBus, Int& addressBus, Int& controlBus) {
  Bit isOutputData, isOutputAddress, isOutputControl, isDestPC, isDestA,
      isDestB, isDestM;
  Int code;
  decode(controlBus, isOutputData, isOutputAddress, isOutputControl, isDestPC,
         isDestA, isDestB, isDestM, code);

  // std::cout << "MEM DETAIL - isOutputData: " << isOutputData
  //           << " isOutputAddress: " << isOutputAddress
  //           << " isOutputControl: " << isOutputControl
  //           << " isDestPC: " << isDestPC << " isDestA: " << isDestA
  //           << " isDestB: " << isDestB << " isDestM: " << isDestM
  //           << " Code: " << code << " Control: " << controlBus << "\n";

  Bit isConst = code == CONST;
  Bit isLoad = code == LOAD;
  Bit isReset = code == RESET;
  Bit isInc = code == INC;

  // Check loading a const
  // addressBus = isConst.mux(addressBus, addressBus + 1);
  isOutputData |= isConst;

  // possibly insert data to mem[addr] and read current content
  Int out = update(dataBus, isLoad && isDestM, addressBus);
  std::cout << "MEM UPDATE - M[" << addressBus << "] = " << out << "\n";
  dataBus = isOutputData.mux(dataBus, out);

  Int newAddress, newControl;
  decode(out, newAddress, newControl);
  Bit isNextConst = newControl == CONST;
  addressBus = isOutputAddress.mux(addressBus, newAddress);
  controlBus = isOutputControl.mux(controlBus, newControl);
  std::cout << "MEM OUTPUTS -  DATA: " << dataBus << " ADDR:" << addressBus
            << " CONTROL: " << controlBus << "\n";
}
