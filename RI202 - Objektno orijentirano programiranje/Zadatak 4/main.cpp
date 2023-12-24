#include <cassert>
#include <iostream>
#include "Complex.h"

int main() {
  Complex a(3, 4);
  assert(a.getReal() == 3 && a.getImag() == 4);

  Complex b(1, -1);
  assert(b.getReal() == 1 && b.getImag() == -1);

  Complex c = a + b;
  assert(c.getReal() == 4 && c.getImag() == 3);

  Complex d = a - b;
  assert(d.getReal() == 2 && d.getImag() == 5);

  Complex e = a * b;
  assert(e.getReal() == 7 && e.getImag() == 1);

  Complex f = a / b;
  assert(f.getReal() == -0.5 && f.getImag() == 3.5);

  a += b;
  assert(a.getReal() == 4 && a.getImag() == 3);

  a -= b;
  assert(a.getReal() == 3 && a.getImag() == 4);

  a *= b;
  assert(a.getReal() == 7 && a.getImag() == 1);

  a /= b;
  assert(a.getReal() == 3 && a.getImag() == 4);

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  std::cout << e << std::endl;
  std::cout << f << std::endl;

  return 0;
}

