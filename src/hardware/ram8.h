#ifndef RAM8_H
#define RAM8_H

#include "bit.h"
#include "int.h"
#include "ram.h"
#include "register.h"

class RAM8 : public RAM {
 public:
  RAM8();
  Int update(Int in, Bit load, Int address);

 private:
  Register reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7;
};
#endif