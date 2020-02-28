#ifndef RAM64_H
#define RAM64_H

#include "bit.h"
#include "int.h"
#include "ram.h"
#include "ram8.h"

class RAM64 : public RAM {
 public:
  RAM64();
  Int update(Int in, Bit load, Int address);

 private:
  RAM8 ram0, ram1, ram2, ram3, ram4, ram5, ram6, ram7;
};
#endif