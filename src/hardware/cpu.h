#ifndef CPU_H
#define CPU_H

#include "bit.h"
#include "hardware.h"
#include "int.h"
#include "register.h"

class CPU : public Hardware {
 public:
  CPU();
  void update(Int& dataBus, Int& addressBus, Int& controlBus);

 private:
  Register regA, regB;
};
#endif