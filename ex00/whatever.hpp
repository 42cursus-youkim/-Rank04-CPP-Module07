#ifndef __WHATEVER_H__
#define __WHATEVER_H__

#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::string;

template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
T& max(T& a, T& b) {
  return (a > b) ? a : b;
}

template <typename T>
T& min(T& a, T& b) {
  return (a < b) ? a : b;
}

/* dummy class */
class Thing {
  private:
    int _value;
  public:
    Thing(int value) : _value(value) {}
    Thing(const Thing& other) : _value(other._value) {}
    Thing & operator=(const Thing& other) {
      _value = other._value;
      return *this;
    }
    ~Thing() {}

    bool operator<(const Thing& other) const {
      return _value < other._value;
    }
    bool operator>(const Thing& other) const {
      return _value > other._value;
    }
    int getValue() const {
      return _value;
    }
};

std::ostream& operator<<(std::ostream& os, const Thing& thing) {
  os << thing.getValue();
  return os;
}

/* tests */
template <typename T>
string pair_to_string(T& a, T& b) {
  std::ostringstream ss;
  ss << "[" << a << "," << b << "]";
  return ss.str();
}

template <typename T>
void test_swap(T& a, T& b) {
  cout << "swap" << pair_to_string(a, b) << "=>";
  swap(a, b);
  cout << pair_to_string(a, b) << "\n";
}

template <typename T>
void test_max(T& a, T& b) {
  cout << "max" << pair_to_string(a, b) << "=>";
  cout << max(a, b) << "\n";
}

template <typename T>
void test_min(T& a, T& b) {
  cout << "min" << pair_to_string(a, b) << "=>";
  cout << min(a, b) << "\n";
}

template <typename T>
void test_all(T& a, T& b, const string& type) {
  cout << "\n<Testing for " << type << ">\n";
  test_swap(a, b);
  test_max(a, b);
  test_min(a, b);
}
#endif  // __WHATEVER_H__