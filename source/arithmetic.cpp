#include <bits/stdc++.h>
class Arithmetic {
 public:
  static int nand1(int a, int b) { return (~(a & b)) & 1; }
  static int not1(int a) { return nand1(a, a); }
  static int and1(int a, int b) { return not1(nand1(a, b)); }
  static int or1(int a, int b) { return nand1(not1(a), not1(b)); }
  static int xor1(int a, int b) { return and1(nand1(a, b), or1(a, b)); }

  static int nand32(int a, int b) { return ~(a & b); }
  static int not32(int a) { return nand32(a, a); }
  static int and32(int a, int b) { return not32(nand32(a, b)); }
  static int or32(int a, int b) { return nand32(not32(a), not32(b)); }
  static int xor32(int a, int b) { return and32(nand32(a, b), or32(a, b)); }

  static void set(int a, int* out, int i) {
    *out = or32(a << i, and32(*out, not32(1 << i)));
  }
  static int get(int a, int i) {  //
    return and1((a >> i), 1);
  }

  static void mux1(int a, int b, int sel, int* out, int i) {
    set(or1(and1(get(a, i), not1(sel)), and1(get(b, i), sel)), out, i);
  }
  static int mux32(int a, int b, int sel) {
    int out = 0;
    mux1(a, b, sel, &out, 0);
    mux1(a, b, sel, &out, 1);
    mux1(a, b, sel, &out, 2);
    mux1(a, b, sel, &out, 3);
    mux1(a, b, sel, &out, 4);
    mux1(a, b, sel, &out, 5);
    mux1(a, b, sel, &out, 6);
    mux1(a, b, sel, &out, 7);
    mux1(a, b, sel, &out, 8);
    mux1(a, b, sel, &out, 9);
    mux1(a, b, sel, &out, 10);
    mux1(a, b, sel, &out, 11);
    mux1(a, b, sel, &out, 12);
    mux1(a, b, sel, &out, 13);
    mux1(a, b, sel, &out, 14);
    mux1(a, b, sel, &out, 15);
    mux1(a, b, sel, &out, 16);
    mux1(a, b, sel, &out, 17);
    mux1(a, b, sel, &out, 18);
    mux1(a, b, sel, &out, 19);
    mux1(a, b, sel, &out, 20);
    mux1(a, b, sel, &out, 21);
    mux1(a, b, sel, &out, 22);
    mux1(a, b, sel, &out, 23);
    mux1(a, b, sel, &out, 24);
    mux1(a, b, sel, &out, 25);
    mux1(a, b, sel, &out, 26);
    mux1(a, b, sel, &out, 27);
    mux1(a, b, sel, &out, 28);
    mux1(a, b, sel, &out, 29);
    mux1(a, b, sel, &out, 30);
    mux1(a, b, sel, &out, 31);
    return out;
  }

  static int or2Way(int a, int i, int j) { return or1(get(a, i), get(a, j)); }
  static int or32Way(int a) {
    return or1(or1(or1(or1(or2Way(a, 0, 1), or2Way(a, 2, 3)),
                       or1(or2Way(a, 4, 5), or2Way(a, 6, 7))),
                   or1(or1(or2Way(a, 8, 9), or2Way(a, 10, 11)),
                       or1(or2Way(a, 12, 13), or2Way(a, 14, 15)))),
               or1(or1(or1(or2Way(a, 16, 17), or2Way(a, 18, 19)),
                       or1(or2Way(a, 20, 21), or2Way(a, 22, 23))),
                   or1(or1(or2Way(a, 24, 25), or2Way(a, 26, 27)),
                       or1(or2Way(a, 28, 29), or2Way(a, 30, 31)))));
  }

  static int halfAdder(int a, int b, int* c) {
    *c = and1(a, b);
    return xor1(a, b);
  }

  static void fullAdder(int a, int b, int* out, int* c, int i) {
    int c1 = 0, c2 = 0;
    set(halfAdder(halfAdder(get(a, i), get(b, i), &c1), *c, &c2), out, i);
    *c = or1(c1, c2);
  }
  static int add32(int a, int b) {
    int out = 0, c = 0;
    fullAdder(a, b, &out, &c, 0);
    fullAdder(a, b, &out, &c, 1);
    fullAdder(a, b, &out, &c, 2);
    fullAdder(a, b, &out, &c, 3);
    fullAdder(a, b, &out, &c, 4);
    fullAdder(a, b, &out, &c, 5);
    fullAdder(a, b, &out, &c, 6);
    fullAdder(a, b, &out, &c, 7);
    fullAdder(a, b, &out, &c, 8);
    fullAdder(a, b, &out, &c, 9);
    fullAdder(a, b, &out, &c, 10);
    fullAdder(a, b, &out, &c, 11);
    fullAdder(a, b, &out, &c, 12);
    fullAdder(a, b, &out, &c, 13);
    fullAdder(a, b, &out, &c, 14);
    fullAdder(a, b, &out, &c, 15);
    fullAdder(a, b, &out, &c, 16);
    fullAdder(a, b, &out, &c, 17);
    fullAdder(a, b, &out, &c, 18);
    fullAdder(a, b, &out, &c, 19);
    fullAdder(a, b, &out, &c, 20);
    fullAdder(a, b, &out, &c, 21);
    fullAdder(a, b, &out, &c, 22);
    fullAdder(a, b, &out, &c, 23);
    fullAdder(a, b, &out, &c, 24);
    fullAdder(a, b, &out, &c, 25);
    fullAdder(a, b, &out, &c, 26);
    fullAdder(a, b, &out, &c, 27);
    fullAdder(a, b, &out, &c, 28);
    fullAdder(a, b, &out, &c, 29);
    fullAdder(a, b, &out, &c, 30);
    fullAdder(a, b, &out, &c, 31);
    return out;
  }
  static int inc32(int a) { return add32(a, 1); }

  int alu32(int a, int b, int za, int na, int zb, int nb, int f, int no,
            int* zr, int* ng) {
    int notA = not32(a), notB = not32(b);
    a = mux32(mux32(a, 0, za), notA, na);
    b = mux32(mux32(b, 0, zb), notB, nb);
    int out = mux32(and32(a, b), add32(a, b), f);
    out = mux32(out, not32(out), no);
    *zr = not32(or32Way(out));
    *ng = get(out, 31);
    return out;
  }
};

int main() {}