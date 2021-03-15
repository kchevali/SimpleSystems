#ifndef BIT_H
#define BIT_H
#include <ostream>

class Int;

class Bit {
 public:
  Bit();
  Bit(int a);
  Bit(Int a);
  int operator<<(const Int& i) const;
  int operator>>(const Int& i) const;

  Bit nand(const Bit& b) const;
  Bit operator!() const;
  Bit operator~() const;
  Bit operator&(const Bit& b) const;
  Bit operator&&(const Bit& b) const;
  Bit operator&=(const Bit& b);
  Bit operator||(const Bit& b) const;
  Bit operator|(const Bit& b) const;
  Bit operator|=(const Bit& b);
  Bit operator^(const Bit& b) const;
  Bit operator^=(const Bit& b);
  Bit mux(const Bit& a, const Bit& b) const;
  void mux(const Int& a, const Int& b, Int& out, const Int& i) const;
  Int mux(const Int& a, const Int& b) const;
  void dmux(const Bit& in, Bit& a, Bit& b) const;
  void dmux(const Int& in, Int& a, Int& b) const;
  void dmux4Way(const Int& sel, Bit& a, Bit& b, Bit& c, Bit& d) const;
  void dmux8Way(const Int& sel, Bit& a, Bit& b, Bit& c, Bit& d, Bit& e, Bit& f,
                Bit& g, Bit& h) const;
  Bit halfAdder(const Bit& a, const Bit& b);
  Bit fullAdder(const Bit& a, const Bit& b);
  int getInt() const;
  bool getBool() const;

  friend std::ostream& operator<<(std::ostream& out, const Bit& c);

 private:
  int a;
};
#endif