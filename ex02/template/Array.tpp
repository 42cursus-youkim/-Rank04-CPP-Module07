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
Array<T>::Array(uint size) : _size(size), _data(new T[size]()) {}

template <typename T>
Array<T>::Array(const Array<T>& other)
    : _size(other._size), _data(new T[other._size]) {
  for (size_t i = 0; i < _size; i++)
    _data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array() {
  delete[] _data;
}

// Operators
template <typename T>
static void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
  Array tmp(other);
  swap(_size, tmp._size);
  swap(_data, tmp._data);
  return *this;
}

template <typename T>
bool Array<T>::is_valid_index(size_t index) const {
  return (0 <= index && index < _size);
}

template <typename T>
const T Array<T>::operator[](size_t index) const {
  if (not is_valid_index(index))
    throw std::out_of_range("(value) Index out of range");
  return _data[index];
}

template <typename T>
T& Array<T>::operator[](size_t index) {
  if (not is_valid_index(index))
    throw std::out_of_range("(reference) Index out of range");
  return _data[index];
}

template <typename T>
size_t Array<T>::size() const {
  return _size;
}

#endif  // __ARRAY_TPP__
