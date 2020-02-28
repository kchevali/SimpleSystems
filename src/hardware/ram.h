#ifndef RAM_H
#define RAM_H

#include "bit.h"
#include "hardware.h"
#include "int.h"

class RAM : public Hardware {
 public:
  RAM(Int capacity);
  void update(Int& dataBus, Int& addressBus, Int& controlBus);
  virtual Int update(Int in, Bit load, Int address) = 0;

 private:
  Int capacity;
};
#endif