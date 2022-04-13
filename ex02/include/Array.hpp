#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stddef.h>

typedef unsigned int uint;

template <typename T>
class Array {
 private:
  uint _size;
  T* _data;

  bool is_valid_index(size_t index) const;

 public:
  // Constructors & Destructors
  Array();
  Array(uint size);
  Array(const Array<T>& other);
  ~Array();

  // Operators
  Array<T>& operator=(const Array<T>& other);
  T& operator[](size_t index);
  const T operator[](size_t index) const;
  size_t size() const;
};

// Template implementations
#include "Array.tpp"

#endif  // __ARRAY_H__
