#ifndef PROCESS_H
#define PROCESS_H

#include "../hardware/int.h"

class Process {
 public:
  Process(Int ptr, Int length);

 private:
  Int ptr, length;
};

#endif