#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <sys/types.h>

// create a orthodox canonical c++ class below
//  generate constructor, destructor, copy assignment
//  name's Array.
template <typename T>
class Array {
 private:
  uint _size;
  T* _data;

  bool is_valid_index(int index) const;

 public:
  // Constructors & Destructors
  Array();
  Array(uint size);
  Array(const Array<T>& other);
  ~Array();

  // Operators
  Array<T>& operator=(const Array<T>& other);
  T& operator[](int index);
  const T operator[](int index) const;
  int size() const;
};

// Template implementations
#include "Array.tpp"

#endif  // __ARRAY_H__