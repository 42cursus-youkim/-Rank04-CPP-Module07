#ifndef __WHATEVER_H__
#define __WHATEVER_H__

#include <iostream>
#include <sstream>
#include <string>
#include "util.hpp"

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

/* tests */
template <typename T>
string pair_to_string(T& a, T& b) {
  std::ostringstream ss;
  ss << MAG "(" BBLU << a << BLU ", " BBLU << b << MAG ")";
  return ss.str();
}

template <typename T>
void test_swap(T& a, T& b) {
  cout << YEL "swap" << pair_to_string(a, b) << RED " -> ";
  swap(a, b);
  cout << pair_to_string(a, b) << "\n";
}

template <typename T>
void test_max(T& a, T& b) {
  cout << YEL "max" << pair_to_string(a, b) << RED " -> " BBLU;
  cout << max(a, b) << "\n";
}

template <typename T>
void test_min(T& a, T& b) {
  cout << YEL "min" << pair_to_string(a, b) << RED " -> " BBLU;
  cout << min(a, b) << "\n";
}

template <typename T>
void test_cmp(T& a, T& b, const string& type) {
  test::subject(type);
  test_max(a, b);
  test_min(a, b);
}

template <typename T>
void test_all(T& a, T& b, const string& type) {
  test_cmp(a, b, type);
  test_swap(a, b);
}

#endif  // __WHATEVER_H__
