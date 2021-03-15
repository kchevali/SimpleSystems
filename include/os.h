#ifndef OS_H
#define OS_H

#include "computer.h"
#include "int.h"

class OS {
 public:
  OS(Computer& computer);
  void loadConst(Int value) const;
  void halt() const;

 private:
  Computer& computer;
};

#endif