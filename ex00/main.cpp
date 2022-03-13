#include <iostream>
#include "whatever.hpp"

using std::cout;

int main(void) {
  {
    int a = 42, b = 24, c = 20, d = 20;
    test_all(a, b, "int");
    test_all(c, d, "same int");
  }
  {
    double a = 42.42, b = 24.24, c = 20.20, d = 20.20;
    test_all(a, b, "double");
    test_all(c, d, "same double");
  }
  {
    std::string a = "42", b = "24", c = "20", d = "20";
    std::string e = "abc", f = "def", g = "bye", h = "bye";
    test_all(a, b, "string");
    test_all(c, d, "same string");
    test_all(e, f, "string");
    test_all(g, h, "same string");
  }
  {
    Thing a(42), b(24), c(20), d(20);
    test_all(a, b, "Thing");
    test_all(c, d, "same Thing");
  }
  return 0;
}
