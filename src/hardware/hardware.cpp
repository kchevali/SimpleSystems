#include "hardware.h"
#include "bit.h"
#include "int.h"
#include <iostream>
#include <sstream>

void Hardware::decode(const Int& instruction, Int& address,
                      Int& control) const {
  address = (instruction >> 16) & 0xFFFF;
  control = instruction & 0xFFFF;
  std::cout << "Instruction: " << hex(instruction)
            << " Address: " << hex(address) << " Control: " << hex(control)
            << "\n";
}

std::string Hardware::hex(const Int num) const {
  std::stringstream stream;
  stream << std::hex << num;
  std::string result(stream.str());
  return result;
}
