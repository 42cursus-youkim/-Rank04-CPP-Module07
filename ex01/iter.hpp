#ifndef __ITER_H__
#define __ITER_H__

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::string;

template <typename T>
void iter(const T array[], size_t len, void (*func)(const T& elem)) {
  for (size_t i = 0; i < len; i++)
    func(array[i]);
}

template <typename T>
void printAny(const T& value) {
  cout << value << ", ";
}

#endif  // __ITER_H__
