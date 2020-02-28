#include "pc.h"
#include <iostream>
#include "bit.h"
#include "int.h"

PC::PC() { counter = Register(); }

void PC::update(Int& dataBus, Int& addressBus, Int& controlBus) {
  Bit isOutputData, isOutputAddress, isOutputControl, isDestPC, isDestA,
      isDestB, isDestM;
  Int code;
  decode(controlBus, isOutputData, isOutputAddress, isOutputControl, isDestPC,
         isDestA, isDestB, isDestM, code);
  Bit isJMP = (code == JNZ && dataBus != 0) || code == JMP;
  Bit isLoad = code == LOAD;
  Bit isReset = code == RESET;
  Bit isConst = code == CONST;
  Bit isInc = (code == INC) | isConst;
  isOutputAddress = isOutputAddress | isConst;
  counter.update(counter.update(0, isReset) + 1, isInc);
  counter.update(addressBus, isJMP);
  addressBus = isOutputAddress.mux(addressBus,
                                   counter.update(dataBus, isLoad & isDestPC));
  // std::cout << "PC UPDATE - INC: " << isInc << " ADDR: " << addressBus <<
  // "\n";
}