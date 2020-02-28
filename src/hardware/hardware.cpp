#include "hardware.h"
#include "bit.h"
#include "int.h"

Hardware::Hardware() { this->index = ++hardwareCounter; }

void Hardware::decode(const Int& controlBus, Bit& isOutputData,
                      Bit& isOutputAddress, Bit& isOutputControl, Bit& isDestPC,
                      Bit& isDestA, Bit& isDestB, Bit& isDestM,
                      Int& code) const {
  Int output = controlBus >> 10;
  isOutputData = (Int(dataBit) & output) == dataBit;
  isOutputAddress = (Int(addressBit) & output) == addressBit;
  isOutputControl = (Int(controlBit) & output) == controlBit;

  Int location = Int(0b11) & (controlBus >> 8);
  isDestPC = location == destPC;
  isDestA = location == destA;
  isDestB = location == destB;
  isDestM = location == destM;

  decode(controlBus, code);
}

void Hardware::decode(const Int& controlBus, Int& code) const {
  code = Int(0xFF) & controlBus;
}

void Hardware::decode(const Int& instruction, Int& address,
                      Int& control) const {
  address = (instruction >> 16) & 0xFFFF;
  control = instruction & 0xFFFF;
}

Int Hardware::encode(const Int& outputBits, const Int& destBits,
                     const Int& code) const {
  return (outputBits << 10) | (destBits << 8) | code;
}

Bit Hardware::operator==(Hardware& that) const {
  return this->index == that.index;
}

Bit Hardware::operator!=(Hardware& that) const {
  return this->index != that.index;
}