#include "ram8.h"
#include "bit.h"
#include "int.h"
#include "ram.h"
#include "register.h"

RAM8::RAM8()
    : RAM(8), reg0(), reg1(), reg2(), reg3(), reg4(), reg5(), reg6(), reg7() {}
Int RAM8::update(Int in, Bit load, Int address) {
  Bit a, b, c, d, e, f, g, h;
  load.dmux8Way(address, a, b, c, d, e, f, g, h);
  return address.mux8Way(reg0.update(in, a), reg1.update(in, b),
                         reg2.update(in, c), reg3.update(in, d),
                         reg4.update(in, e), reg5.update(in, f),
                         reg6.update(in, g), reg7.update(in, h));
}