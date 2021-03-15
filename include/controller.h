#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "bit.h"
#include "hardware.h"
#include "int.h"

class Computer;
class Controller : public Hardware {
 public:
  Controller(Computer& computer);
  void run();
  void update(Int& dataBus, Int& addressBus, Int& controlBus);

 private:
  Bit isHalt;
  Computer& computer;
};
#endif