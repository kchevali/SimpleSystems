#include "cpu.h"
#include "bit.h"
#include "int.h"
#include "register.h"
#include <iostream>

CPU::CPU() : regA(), regB() {}
void CPU::update(Int& dataBus, Int& addressBus, Int& controlBus) {
  Bit isCPU = controlBus[CPUL];
  Bit isDestB = isCPU & controlBus[0];
  Bit isDestA = isCPU & ~isDestB;
  Int valA = regA.read(), valB = regB.read();
  Int x = isDestA.mux(valB, valA), y = isDestA.mux(valA, valB);
  Int out = 0;  // handles the RESET case

  Bit isComplex = isCPU & controlBus[OP];
  Bit isAdd = isComplex & controlBus[OP1];
  Bit isSub = isComplex & controlBus[OP2];
  Bit isMult = isComplex & controlBus[OP3];
  Bit isDiv = isComplex & controlBus[OP4];

  out = isAdd.mux(out, x + y);
  out = isSub.mux(out, x - y);
  out = isMult.mux(out, x * y);
  out = isDiv.mux(out, x / y);

  Bit isBasic = isCPU & (~isComplex);
  Bit isAnd = isBasic & controlBus[OP1];
  Bit isOr = isBasic & controlBus[OP2];
  Bit isXor = isBasic & controlBus[OP3];
  Bit isNot = isBasic & controlBus[OP4];

  out = isAnd.mux(out, x & y);
  out = isOr.mux(out, x | y);
  out = isXor.mux(out, x ^ y);
  out = isNot.mux(out, ~x);

  // load
  Bit isLoad = isCPU & controlBus[LOAD];
  out = isLoad.mux(out, dataBus);

  // move
  Bit isMove = controlBus[MOV];
  out = (isDestA && isMove).mux(out, valB);
  out = (isDestB && isMove).mux(out, valA);

  // inc
  Bit isInc = isCPU & controlBus[INC];
  out = (isDestA && isInc).mux(out, valA + 1);
  out = (isDestB && isInc).mux(out, valB + 1);

  std::cout << "CPU | isDestPC: " << isCPU << " isLoad: " << isLoad
            << " isInc: " << isInc << " isDestA: " << isDestA
            << " isDestB: " << isDestB << " isMove: " << isMove << "\n";

  Int a = regA.update(out, isDestA);
  Int b = regB.update(out, isDestB);

  Bit isOutputData = isCPU & controlBus[DATA];
  Bit isOutputAddress = isCPU & controlBus[ADDR];
  Bit isOutputControl = isCPU & controlBus[CONTROL];
  dataBus = isOutputData.mux(dataBus, out);
  addressBus = isOutputAddress.mux(addressBus, out);
  controlBus = isOutputControl.mux(controlBus, out);
  std::cout << "CPU UPDATE - A: " << a << " B: " << b
            << " OUT: " << hex(dataBus) << "\n";
}