#ifndef __ITER_H__
#define __ITER_H__

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::string;

template <typename T>
void iter(T array[], size_t len, void (*func)(T& array)) {
  for (size_t i = 0; i < len; i++)
    func(array[i]);
}

template <typename T>
void printAny(T& value) {
  cout << value << ", ";
}

template <typename T>
void testwithType(T array[], const string& type_name) {
  cout << "\n<Testing for " << type_name << ">\n";
  iter(array, 10, printAny<T>);
  cout << "\n";
}
#endif  // __ITER_H__