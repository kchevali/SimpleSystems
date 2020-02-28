#include "bit.h"
#include "int.h"

Bit::Bit() { this->a = 0; }
Bit::Bit(int a) { this->a = a & 1; }
Bit::Bit(Int a) { this->a = a.getInt() & 1; }

Bit Bit::nand(const Bit& b) const { return (~(a & b.a)) & 1; }
Bit Bit::operator!() const { return nand(a); }
Bit Bit::operator~() const { return nand(a); }
Bit Bit::operator&(const Bit& b) const { return !nand(b); }
Bit Bit::operator&=(const Bit& b) { return *this = *this & b; }
Bit Bit::operator&&(const Bit& b) const { return !nand(b); }
Bit Bit::operator||(const Bit& b) const { return (!(*this)).nand(!b); }
Bit Bit::operator|(const Bit& b) const { return (!(*this)).nand(!b); }
Bit Bit::operator|=(const Bit& b) { return *this = *this | b; }
Bit Bit::operator^(const Bit& b) const { return nand(b) & ((*this) | b); }
Bit Bit::operator^=(const Bit& b) { return *this = *this ^ b; }
// Mux Operation
Bit Bit::mux(const Bit& a, const Bit& b) const {
  return (a & !(*this)) | (b & *this);
}
void Bit::mux(const Int& a, const Int& b, Int& out, const Int& i) const {
  out.set(i, mux(a[i], b[i]));
}
Int Bit::mux(const Int& a, const Int& b) const {
  Int out = 0;
  mux(a, b, out, 0);
  mux(a, b, out, 1);
  mux(a, b, out, 2);
  mux(a, b, out, 3);
  mux(a, b, out, 4);
  mux(a, b, out, 5);
  mux(a, b, out, 6);
  mux(a, b, out, 7);
  mux(a, b, out, 8);
  mux(a, b, out, 9);
  mux(a, b, out, 10);
  mux(a, b, out, 11);
  mux(a, b, out, 12);
  mux(a, b, out, 13);
  mux(a, b, out, 14);
  mux(a, b, out, 15);
  mux(a, b, out, 16);
  mux(a, b, out, 17);
  mux(a, b, out, 18);
  mux(a, b, out, 19);
  mux(a, b, out, 20);
  mux(a, b, out, 21);
  mux(a, b, out, 22);
  mux(a, b, out, 23);
  mux(a, b, out, 24);
  mux(a, b, out, 25);
  mux(a, b, out, 26);
  mux(a, b, out, 27);
  mux(a, b, out, 28);
  mux(a, b, out, 29);
  mux(a, b, out, 30);
  mux(a, b, out, 31);
  return out;
}

void Bit::dmux(const Bit& in, Bit& a, Bit& b) const {
  a = mux(in, 0);
  b = mux(0, in);
}

void Bit::dmux(const Int& in, Int& a, Int& b) const {
  a = mux(in, 0);
  b = mux(0, in);
}

void Bit::dmux4Way(const Int& sel, Bit& a, Bit& b, Bit& c, Bit& d) const {
  Int x = 0, y = 0;
  sel[0].dmux(*this, x, y);
  sel[1].dmux(x, a, c);
  sel[1].dmux(y, b, d);
}
void Bit::dmux8Way(const Int& sel, Bit& a, Bit& b, Bit& c, Bit& d, Bit& e,
                   Bit& f, Bit& g, Bit& h) const {
  Bit x = 0, y = 0;
  sel[2].dmux(*this, x, y);
  x.dmux4Way(sel, a, b, c, d);
  y.dmux4Way(sel, e, f, g, h);
}

Bit Bit::halfAdder(const Bit& a, const Bit& b) {
  *this = a & b;
  return a ^ b;
}

Bit Bit::fullAdder(const Bit& a, const Bit& b) {
  Bit c1 = 0, c2 = 0;
  Bit out = c2.halfAdder(*this, c1.halfAdder(a, b));
  *this = c1 | c2;
  return out;
}

std::ostream& operator<<(std::ostream& out, const Bit& c) {
  out << c.a;
  return out;
}

int Bit::getInt() const { return a; }
bool Bit::getBool() const { return a == 1; }