#ifndef OS_H
#define OS_H

#include "../hardware/computer.h"
#include "../hardware/int.h"

class OS {
 public:
  OS(Computer& computer);
  void loadConst(Int value) const;
  void halt() const;

 private:
  Computer& computer;
};

#endif