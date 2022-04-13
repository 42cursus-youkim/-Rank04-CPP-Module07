#include "MyInt.hpp"

// Constructors & Destructor
MyInt::MyInt() : _n(0){};
MyInt::MyInt(int n) : _n(n){};
MyInt::~MyInt(){};

// Operators
MyInt& MyInt::operator=(const MyInt& other) {
  _n = other._n;
  return *this;
}
bool MyInt::operator==(const MyInt& other) {
  return _n == other._n;
}
bool MyInt::operator!=(const MyInt& other) {
  return _n != other._n;
}
bool MyInt::operator>(const MyInt& other) {
  return _n > other._n;
}
bool MyInt::operator<(const MyInt& other) {
  return _n < other._n;
}
bool MyInt::operator>=(const MyInt& other) {
  return _n >= other._n;
}
bool MyInt::operator<=(const MyInt& other) {
  return _n <= other._n;
}

// Getters/Setters
int MyInt::getNum() const {
  return _n;
}

std::ostream& operator<<(std::ostream& os, const MyInt& n) {
  os << n.getNum();
  return os;
}
