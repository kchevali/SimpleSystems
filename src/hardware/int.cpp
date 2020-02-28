
#include "int.h"
#include <ostream>
#include "bit.h"

// Constructors
Int::Int() { this->a = 0; }
Int::Int(int a) { this->a = a; }
Int::Int(Bit b) { this->a = b.getInt(); }

// Fundamental Operations
// Only place where default c++ operations can be used
Int Int::nand(const Int& b) const { return ~(a & b.a); }
Int Int::operator<<(const Int& b) const { return a << b.a; }
Int Int::operator>>(const Int& b) const { return a >> b.a; }
Int Int::operator<<=(const Int& b) { return a = a << b.a; }
Int Int::operator>>=(const Int& b) { return a = a >> b.a; }

// Basic Operations
Int Int::operator~() const { return nand(a); }
Int Int::operator&(const Int& b) const { return ~nand(b); }
Int Int::operator|(const Int& b) const { return (~(*this)).nand(~b); }
Int Int::operator^(const Int& b) const { return nand(b) & ((*this) | b); }
Int Int::operator&=(const Int& b) { return *this = *this & b; }
Int Int::operator|=(const Int& b) { return *this = *this | b; }
Int Int::operator^=(const Int& b) { return *this = *this ^ b; }

// Set/Get bit
void Int::set(const Int& i, const Bit& b) {
  *this = (Int(b) << i) | (*this & ~(Int(1) << i));
}
Bit Int::operator[](const Int& i) const { return Bit(*this >> i) & Bit(1); }

Bit Int::mux4Way(const Bit& a, const Bit& b, const Bit& c, const Bit& d) const {
  return (*this)[1].mux((*this)[0].mux(a, b), (*this)[0].mux(c, d));
}
Bit Int::mux8Way(const Bit& a, const Bit& b, const Bit& c, const Bit& d,
                 const Bit& e, const Bit& f, const Bit& g, const Bit& h) const {
  return (*this)[2].mux(mux4Way(a, b, c, d), mux4Way(e, f, g, h));
}

Int Int::mux4Way(const Int& a, const Int& b, const Int& c, const Int& d) const {
  return (*this)[1].mux((*this)[0].mux(a, b), (*this)[0].mux(c, d));
}
Int Int::mux8Way(const Int& a, const Int& b, const Int& c, const Int& d,
                 const Int& e, const Int& f, const Int& g, const Int& h) const {
  return (*this)[2].mux(mux4Way(a, b, c, d), mux4Way(e, f, g, h));
}

void Int::dmux4Way(const Int& sel, Int& a, Int& b, Int& c, Int& d) const {
  Int x = 0, y = 0;
  sel[0].dmux(*this, x, y);
  sel[1].dmux(x, a, c);
  sel[1].dmux(y, b, d);
}
void Int::dmux8Way(const Int& sel, Int& a, Int& b, Int& c, Int& d, Int& e,
                   Int& f, Int& g, Int& h) const {
  Int x = 0, y = 0;
  sel[2].dmux(*this, x, y);
  x.dmux4Way(sel, a, b, c, d);
  y.dmux4Way(sel, e, f, g, h);
}

// Or Way Operations
Bit Int::or2Way(const Int& i, const Int& j) const {
  return (*this)[i] | (*this)[j];
}
Bit Int::or32Way() const {
  return or2Way(0, 1) | or2Way(2, 3) | or2Way(4, 5) | or2Way(6, 7) |
         or2Way(8, 9) | or2Way(10, 11) | or2Way(12, 13) | or2Way(14, 15) |
         or2Way(16, 17) | or2Way(18, 19) | or2Way(20, 21) | or2Way(22, 23) |
         or2Way(24, 25) | or2Way(26, 27) | or2Way(28, 29) | or2Way(30, 31);
}

// Addition
void Int::fullAdder(const Int& a, const Int& b, Bit& c, const Int& i) {
  set(i, c.fullAdder(a[i], b[i]));
}
Int Int::operator+(const Int& b) const {
  Int out = 0;
  Bit c = 0;
  out.fullAdder(*this, b, c, 0);
  out.fullAdder(*this, b, c, 1);
  out.fullAdder(*this, b, c, 2);
  out.fullAdder(*this, b, c, 3);
  out.fullAdder(*this, b, c, 4);
  out.fullAdder(*this, b, c, 5);
  out.fullAdder(*this, b, c, 6);
  out.fullAdder(*this, b, c, 7);
  out.fullAdder(*this, b, c, 8);
  out.fullAdder(*this, b, c, 9);
  out.fullAdder(*this, b, c, 10);
  out.fullAdder(*this, b, c, 11);
  out.fullAdder(*this, b, c, 12);
  out.fullAdder(*this, b, c, 13);
  out.fullAdder(*this, b, c, 14);
  out.fullAdder(*this, b, c, 15);
  out.fullAdder(*this, b, c, 16);
  out.fullAdder(*this, b, c, 17);
  out.fullAdder(*this, b, c, 18);
  out.fullAdder(*this, b, c, 19);
  out.fullAdder(*this, b, c, 20);
  out.fullAdder(*this, b, c, 21);
  out.fullAdder(*this, b, c, 22);
  out.fullAdder(*this, b, c, 23);
  out.fullAdder(*this, b, c, 24);
  out.fullAdder(*this, b, c, 25);
  out.fullAdder(*this, b, c, 26);
  out.fullAdder(*this, b, c, 27);
  out.fullAdder(*this, b, c, 28);
  out.fullAdder(*this, b, c, 29);
  out.fullAdder(*this, b, c, 30);
  out.fullAdder(*this, b, c, 31);
  return out;
}
Int Int::operator+=(const Int& b) { return *this = *this + b; }
Int Int::operator++() { return *this = *this + 1; }
Int Int::operator++(int x) { return *this = *this + 1; }
Int Int::operator-(const Int& b) const { return *this + ~b + 1; }
Int Int::operator-=(const Int& b) { return *this = *this - b; }
Int Int::operator--() { return *this = *this - 1; }
Int Int::operator--(int x) { return *this = *this - 1; }

Int Int::operator*(const Int& b) const {
  Int out = 0, p = *this;
  out += b[0].mux(0, p);
  out += b[1].mux(0, p <<= 1);
  out += b[2].mux(0, p <<= 1);
  out += b[3].mux(0, p <<= 1);
  out += b[4].mux(0, p <<= 1);
  out += b[5].mux(0, p <<= 1);
  out += b[6].mux(0, p <<= 1);
  out += b[7].mux(0, p <<= 1);
  out += b[8].mux(0, p <<= 1);
  out += b[9].mux(0, p <<= 1);
  out += b[10].mux(0, p <<= 1);
  out += b[11].mux(0, p <<= 1);
  out += b[12].mux(0, p <<= 1);
  out += b[13].mux(0, p <<= 1);
  out += b[14].mux(0, p <<= 1);
  out += b[15].mux(0, p <<= 1);
  out += b[16].mux(0, p <<= 1);
  out += b[17].mux(0, p <<= 1);
  out += b[18].mux(0, p <<= 1);
  out += b[19].mux(0, p <<= 1);
  out += b[20].mux(0, p <<= 1);
  out += b[21].mux(0, p <<= 1);
  out += b[22].mux(0, p <<= 1);
  out += b[23].mux(0, p <<= 1);
  out += b[24].mux(0, p <<= 1);
  out += b[25].mux(0, p <<= 1);
  out += b[26].mux(0, p <<= 1);
  out += b[27].mux(0, p <<= 1);
  out += b[28].mux(0, p <<= 1);
  out += b[29].mux(0, p <<= 1);
  out += b[30].mux(0, p <<= 1);
  out += b[31].mux(0, p <<= 1);
  return out;
}

Int Int::operator*=(const Int& b) { return *this = *this * b; }

// run on the numerator
void Int::div(const Int& d, Int& q, Int& r, const Int& i) const {
  r <<= 1;
  r.set(0, (*this)[i]);

  Bit cond = (r >= d);
  r -= cond.mux(0, d);
  q.set(i, cond.mux(q[i], 1));
}
void Int::div(const Int& b, Int& q, Int& r) const {
  q = 0;
  r = 0;
  div(b, q, r, 31);
  div(b, q, r, 30);
  div(b, q, r, 29);
  div(b, q, r, 28);
  div(b, q, r, 27);
  div(b, q, r, 26);
  div(b, q, r, 25);
  div(b, q, r, 24);
  div(b, q, r, 23);
  div(b, q, r, 22);
  div(b, q, r, 21);
  div(b, q, r, 20);
  div(b, q, r, 19);
  div(b, q, r, 18);
  div(b, q, r, 17);
  div(b, q, r, 16);
  div(b, q, r, 15);
  div(b, q, r, 14);
  div(b, q, r, 13);
  div(b, q, r, 12);
  div(b, q, r, 11);
  div(b, q, r, 10);
  div(b, q, r, 9);
  div(b, q, r, 8);
  div(b, q, r, 7);
  div(b, q, r, 6);
  div(b, q, r, 5);
  div(b, q, r, 4);
  div(b, q, r, 3);
  div(b, q, r, 2);
  div(b, q, r, 1);
  div(b, q, r, 0);
}
Int Int::operator/(const Int& b) const {
  Int q, r;
  div(b, q, r);
  return q;
}
Int Int::operator/=(const Int& b) { return *this = *this / b; }
Int Int::operator%(const Int& b) const {
  Int q, r;
  div(b, q, r);
  return r;
}
Int Int::operator%=(const Int& b) { return *this = *this % b; }

Bit Int::operator<(const Int& b) const { return (*this - b)[31]; }
Bit Int::operator>(const Int& b) const { return (b - *this)[31]; }
Bit Int::operator!=(const Int& b) const { return (*this - b).or32Way(); }
Bit Int::operator==(const Int& b) const { return !(*this != b); }
Bit Int::operator<=(const Int& b) const { return !(*this > b); }
Bit Int::operator>=(const Int& b) const { return !(*this < b); }

std::ostream& operator<<(std::ostream& out, const Int& c) {
  out << c.a;
  return out;
}

int Int::getInt() const { return a; }