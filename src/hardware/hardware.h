#ifndef HARDWARE_H
#define HARDWARE_H
#include "int.h"

class Hardware {
 public:
  Hardware();

  virtual void update(Int& dataBus, Int& addressBus, Int& controlBus) = 0;
  void decode(const Int& controlBus, Bit& isOutputData, Bit& isOutputAddress,
              Bit& isOutputControl, Bit& isDestPC, Bit& isDestA, Bit& isDestB,
              Bit& isDestM, Int& code) const;
  void decode(const Int& controlBus, Int& code) const;
  void decode(const Int& instruction, Int& address, Int& control) const;
  Int encode(const Int& outputBits, const Int& destBits, const Int& code) const;

  Bit operator==(Hardware& that) const;
  Bit operator!=(Hardware& that) const;

  static Int hardwareCounter;

 private:
  Int index;

 protected:
  static const int HALT = 0b00000000;   // - HALT
  static const int AND = 0b00000001;    // - &
  static const int OR = 0b00000010;     // - |
  static const int XOR = 0b00000011;    // - ^
  static const int ADD = 0b00000100;    // - +
  static const int SUB = 0b00000101;    // - -
  static const int MULT = 0b00000110;   // - *
  static const int DIV = 0b00000111;    // - /
  static const int MOD = 0b00001000;    // - %
  static const int RIGHT = 0b00001001;  // - >>
  static const int LEFT = 0b00001010;   // - <<
  static const int GT = 0b00001011;     // - >
  static const int LT = 0b00001100;     // - <
  static const int GE = 0b00001101;     // - >=
  static const int LE = 0b00001110;     // - <=
  static const int EQUAL = 0b00001111;  // - ==
  static const int NE = 0b00010000;     // - !=
  static const int NOT = 0b00010001;    // - ~
  static const int JNZ = 0b00010010;    // - JNZ
  static const int JMP = 0b00010011;    // - JMP
  static const int LOAD = 0b00010100;   // - LOAD
  static const int MOVE = 0b00010101;   // - MOVE
  static const int CONST = 0b00010110;  // - CONST
  static const int RESET = 0b00010111;  // - RESET
  static const int INC = 0b00011000;    // - INC
  static const int PRINT = 0b00011001;  // - PRINT MEM
  static const int NOP = 0xFF;          // NOP

  static const int destPC = 0b00;
  static const int destA = 0b01;
  static const int destB = 0b10;
  static const int destM = 0b11;

  static const int dataBit = 0b100;
  static const int addressBit = 0b010;
  static const int controlBit = 0b001;
};

#endif