#ifndef RAM512_H
#define RAM512_H

#include "bit.h"
#include "int.h"
#include "ram.h"
#include "ram64.h"

class RAM512 : public RAM {
 public:
  RAM512();
  Int update(Int in, Bit load, Int address);

 private:
  RAM64 ram0, ram1, ram2, ram3, ram4, ram5, ram6, ram7;
};
#endif