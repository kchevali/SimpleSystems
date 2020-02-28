#ifndef PC_H
#define PC_H

#include "bit.h"
#include "hardware.h"
#include "int.h"
#include "register.h"

class PC : public Hardware {
 public:
  PC();
  void update(Int& dataBus, Int& addressBus, Int& controlBus);

 private:
  Register counter;
};
#endif