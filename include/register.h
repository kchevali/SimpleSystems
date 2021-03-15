#ifndef REGISTER_H
#define REGISTER_H

#include <ostream>
#include "bit.h"
#include "int.h"

class Register {
 public:
  Register();
  Int update(Int in, Bit load);
  Int read();

 private:
  Int mem;
};
#endif