#ifndef __MYINT_H__
#define __MYINT_H__

#include <iostream>

class MyInt {
 private:
  int _n;

 public:
  // Constructors & Destructor
  MyInt();
  MyInt(int n);
  ~MyInt();

  // Operators
  MyInt& operator=(const MyInt& other);
  bool operator==(const MyInt& other) const;
  bool operator!=(const MyInt& other) const;
  bool operator>(const MyInt& other) const;
  bool operator<(const MyInt& other) const;
  bool operator>=(const MyInt& other) const;
  bool operator<=(const MyInt& other) const;

  // Getters/Setters
  int getNum() const;
};

std::ostream& operator<<(std::ostream& os, const MyInt& n);

#endif  // __MYINT_H__
