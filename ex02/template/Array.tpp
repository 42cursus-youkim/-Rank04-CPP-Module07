#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include <stddef.h>
#include <stdexcept>
#include "Array.hpp"

#ifndef __ARRAY_H__
#error "You must include Array.hpp before Array.tpp"
#endif

// Constructors & Destructors
template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(uint size) : _size(size), _data(new T[size]) {}

template <typename T>
Array<T>::Array(const Array<T>& other)
    : _size(other._size), _data(new T[other._size]) {
  for (uint i = 0; i < _size; i++)
    _data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array() {
  delete[] _data;
}

// Operators
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
  if (this != &other) {
    delete[] _data;
    _size = other._size;
    _data = new T[other._size];
    for (uint i = 0; i < _size; i++)
      _data[i] = other._data[i];
  }
  return *this;
}

template <typename T>
bool Array<T>::is_valid_index(int index) const {
  return (0 <= index && static_cast<size_t>(index) < _size);
}

template <typename T>
const T Array<T>::operator[](int index) const {
  if (not is_valid_index(index))
    throw std::out_of_range("(value) Index out of range");
  return _data[index];
}

template <typename T>
T& Array<T>::operator[](int index) {
  if (not is_valid_index(index))
    throw std::out_of_range("(reference) Index out of range");
  return _data[index];
}

template <typename T>
int Array<T>::size() const {
  return _size;
}

#endif  // __ARRAY_TPP__