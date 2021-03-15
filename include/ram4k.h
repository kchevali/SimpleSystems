#ifndef RAM4K_H
#define RAM4K_H

#include "bit.h"
#include "int.h"
#include "ram.h"
#include "ram512.h"

class RAM4k : public RAM {
 public:
  RAM4k();
  Int update(Int in, Bit load, Int address);

 private:
  RAM512 ram0, ram1, ram2, ram3, ram4, ram5, ram6, ram7;
};
#endif