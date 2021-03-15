#include "ram512.h"
#include "bit.h"
#include "int.h"
#include "ram.h"
#include "ram64.h"

RAM512::RAM512()
    : RAM(512),
      ram0(),
      ram1(),
      ram2(),
      ram3(),
      ram4(),
      ram5(),
      ram6(),
      ram7() {}
Int RAM512::update(Int in, Bit load, Int address) {
  Bit a, b, c, d, e, f, g, h;
  load.dmux8Way(address >> 6, a, b, c, d, e, f, g, h);
  return (address >> 6)
      .mux8Way(ram0.update(in, a, address), ram1.update(in, b, address),
               ram2.update(in, c, address), ram3.update(in, d, address),
               ram4.update(in, e, address), ram5.update(in, f, address),
               ram6.update(in, g, address), ram7.update(in, h, address));
}