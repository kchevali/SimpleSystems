#include "cpu.h"
#include <iostream>
#include "bit.h"
#include "int.h"
#include "register.h"

CPU::CPU() : regA(), regB() {}
void CPU::update(Int& dataBus, Int& addressBus, Int& controlBus) {
  Bit isOutputData, isOutputAddress, isOutputControl, isDestPC, isDestA,
      isDestB, isDestM;
  Int code;
  decode(controlBus, isOutputData, isOutputAddress, isOutputControl, isDestPC,
         isDestA, isDestB, isDestM, code);

  Int valA = regA.read(), valB = regB.read();
  Int x = isDestA.mux(valB, valA), y = isDestA.mux(valA, valB);
  Int out = 0;  // handles the RESET case

  out = (code == AND).mux(out, x & y);
  out = (code == OR).mux(out, x | y);
  out = (code == XOR).mux(out, x ^ y);
  out = (code == ADD).mux(out, x + y);
  out = (code == SUB).mux(out, x - y);
  out = (code == MULT).mux(out, x * y);
  out = (code == DIV).mux(out, x / y);
  out = (code == MOD).mux(out, x % y);
  out = (code == RIGHT).mux(out, x >> y);
  out = (code == LEFT).mux(out, x << y);
  out = (code == GT).mux(out, Int(x > y));
  out = (code == LT).mux(out, Int(x < y));
  out = (code == GE).mux(out, Int(x >= y));
  out = (code == LE).mux(out, Int(x <= y));
  out = (code == EQUAL).mux(out, Int(x == y));
  out = (code == NE).mux(out, Int(x != y));
  out = (code == NOT).mux(out, ~x);

  // load
  out = (code == LOAD).mux(out, dataBus);

  // inc
  Bit isInc = code == INC;
  out = (isDestA && isInc).mux(out, valA + 1);
  out = (isDestB && isInc).mux(out, valB + 1);

  // move
  Bit isMove = code == MOVE;
  out = (isDestA && isMove).mux(out, valB);
  out = (isDestB && isMove).mux(out, valA);

  Int a = regA.update(out, isDestA);
  Int b = regB.update(out, isDestB);
  dataBus = isOutputData.mux(dataBus, out);
  std::cout << "CPU UPDATE - A: " << a << " B: " << b << " OUT: " << dataBus
            << "\n";
}