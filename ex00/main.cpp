#include <iostream>
#include "MyInt.hpp"
#include "whatever.hpp"

using std::cout;

int main() {
  test::header("int");
  {
    int a = 42, b = 24, c = 20, d = 20;
    test_all(a, b, "int");
    test_all(c, d, "same int");
  }
  {
    const int a = 42, b = 24, c = 20, d = 20;
    test_cmp(a, b, "const int");
    test_cmp(c, d, "const same int");
  }
  test::header("double");
  {
    double a = 42.42, b = 24.24, c = 20.20, d = 20.20;
    test_all(a, b, "double");
    test_all(c, d, "same double");
  }
  test::header("std::string");
  {
    std::string a = "42", b = "24", c = "20", d = "20";
    std::string e = "abc", f = "def", g = "bye", h = "bye";
    test_all(a, b, "string");
    test_all(c, d, "same string");
    test_all(e, f, "string");
    test_all(g, h, "same string");
  }
  test::header("custom object");
  {
    MyInt a(42), b(24), c(20), d(20);
    test_all(a, b, "MyInt");
    test_all(c, d, "same MyInt");
  }
  return 0;
}
