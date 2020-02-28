#ifndef INT_H
#define INT_H

#include <ostream>

class Bit;

class Int {
 public:
  Int();
  Int(int a);
  Int(Bit b);

  Int nand(const Int& b) const;
  Int operator<<(const Int& b) const;
  Int operator>>(const Int& b) const;
  Int operator<<=(const Int& b);
  Int operator>>=(const Int& b);

  Int operator~() const;
  Int operator&(const Int& b) const;
  Int operator|(const Int& b) const;
  Int operator^(const Int& b) const;
  Int operator&=(const Int& b);
  Int operator|=(const Int& b);
  Int operator^=(const Int& b);

  void set(const Int& i, const Bit& b);
  Bit operator[](const Int& i) const;

  Bit mux4Way(const Bit& a, const Bit& b, const Bit& c, const Bit& d) const;
  Bit mux8Way(const Bit& a, const Bit& b, const Bit& c, const Bit& d,
              const Bit& e, const Bit& f, const Bit& g, const Bit& h) const;

  Int mux4Way(const Int& a, const Int& b, const Int& c, const Int& d) const;
  Int mux8Way(const Int& a, const Int& b, const Int& c, const Int& d,
              const Int& e, const Int& f, const Int& g, const Int& h) const;

  void dmux4Way(const Int& sel, Int& a, Int& b, Int& c, Int& d) const;
  void dmux8Way(const Int& sel, Int& a, Int& b, Int& c, Int& d, Int& e, Int& f,
                Int& g, Int& h) const;

  Bit or2Way(const Int& i, const Int& j) const;
  Bit or32Way() const;

  void fullAdder(const Int& a, const Int& b, Bit& c, const Int& i);
  Int operator+(const Int& b) const;
  Int operator+=(const Int& b);
  Int operator++();
  Int operator++(int x);
  Int operator-(const Int& b) const;
  Int operator-=(const Int& b);
  Int operator--();
  Int operator--(int x);
  Int operator*(const Int& b) const;
  Int operator*=(const Int& b);
  void div(const Int& d, Int& q, Int& r, const Int& i) const;
  void div(const Int& b, Int& q, Int& r) const;
  Int operator/(const Int& b) const;
  Int operator/=(const Int& b);
  Int operator%(const Int& b) const;
  Int operator%=(const Int& b);
  int getInt() const;

  Bit operator<(const Int& b) const;
  Bit operator>(const Int& b) const;
  Bit operator!=(const Int& b) const;
  Bit operator==(const Int& b) const;
  Bit operator<=(const Int& b) const;
  Bit operator>=(const Int& b) const;

  friend std::ostream& operator<<(std::ostream& out, const Int& c);

 private:
  int a;
};
#endif

// 10101    21
// 00111    07
