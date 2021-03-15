#ifndef HARDWARE_H
#define HARDWARE_H
#include "int.h"
#include <iostream>

class Hardware {
 public:
  virtual void update(Int& dataBus, Int& addressBus, Int& controlBus) = 0;
  void decode(const Int& instruction, Int& address, Int& control) const;

  std::string hex(const Int num) const;

 protected:
  static const int PCL = 15;
  static const int CPUL = 14;
  static const int ML = 13;
  static const int DATA = 12;
  static const int ADDR = 11;
  static const int CONTROL = 10;

  static const int LOAD = 1;
  static const int CONST = 2;
  static const int INC = 2;
  static const int JMP = 4;
  static const int JNZ = 5;
  static const int JLT = 6;
  static const int JGT = 7;
  static const int JLE = 8;
  static const int JGE = 9;
  static const int REG = 0;
  static const int MOV = 3;
  static const int OP = 4;
  static const int OP1 = 5;
  static const int OP2 = 6;
  static const int OP3 = 7;
  static const int OP4 = 8;
};

#endif